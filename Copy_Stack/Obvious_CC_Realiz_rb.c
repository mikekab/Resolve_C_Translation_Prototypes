#include "Obvious_CC_Realiz_rb.h"
#include "Stack_Template_co.h"
#include "Integers.h"
/*
    Procedure Copy_Stack(replaces S_Copy: Stack; restores S_Orig: Stack);
        Var Next_Entry, Entry_Copy: Entry;
        Var S_Reversed: Stack;

        While (Depth(S_Orig) /= 0)
		changing Next_Entry, S_Orig, S_Reversed;
            maintaining #S_Orig = Reverse(S_Reversed) o S_Orig;
            decreasing |S_Orig|;
        do
            Pop(Next_Entry, S_Orig);
            Push(Next_Entry, S_Reversed);
        end;
        Clear(S_Copy);
        While (Depth(S_Reversed) /= 0)
		changing Entry_Copy, Next_Entry, S_Copy, S_Orig, S_Reversed;
            maintaining S_Copy = S_Orig and
                        #S_Orig = Reverse(S_Reversed) o S_Orig;
            decreasing |S_Reversed|;
        do
            Pop(Next_Entry, S_Reversed);
            Copy_Entry(Entry_Copy, Next_Entry);
            Push(Next_Entry, S_Orig);
            Push(Entry_Copy, S_Copy);
        end;
    end Copy_Stack;

end Obvious_CC_Realiz;
*/

// Procedure Copy_Stack(replaces S_Copy: Stack; restores S_Orig: Stack);
void Copy_Stack (r_type_ptr S_Copy, r_type_ptr S_Orig, Stack_Template* StackFac, Copy_Capability_for_Stack_Template* thisFac)
{
    // this cast is known from the translation of the resolve code
    void (*Copy_Entry)(r_type_ptr, r_type_ptr) = thisFac->OptionalParameters;
    //Var Next_Entry, Entry_Copy: Entry;
    r_type_ptr Next_Entry = StackFac->TypeEntry->init(StackFac->TypeEntry);
    r_type_ptr Entry_Copy = StackFac->TypeEntry->init(StackFac->TypeEntry);
    //Var S_Reversed: Stack;
    r_type_ptr S_Reversed = StackFac->Stack->init(StackFac->Stack);

    // Setting up an emulation of a local Integer type used to capture the return of Depth
    // when it is not otherwise captured.
    r_type_ptr DepthReturn = IF->IntTypeInfo->init(IF->IntTypeInfo);
    //While (Depth(S_Orig) /= 0)
    while( IF->ValueOf(StackFac->Depth(S_Orig, DepthReturn, StackFac))){
        //do
        //Pop(Next_Entry, S_Orig);
        StackFac->Pop(Next_Entry, S_Orig, StackFac);
        //Push(Next_Entry, S_Reversed);
        StackFac->Push(Next_Entry, S_Reversed, StackFac);
    }//end;
    //Clear(S_Copy);
    StackFac->Clear(S_Copy, StackFac);
    //While (Depth(S_Reversed) /= 0)
    while( IF->ValueOf(StackFac->Depth(S_Reversed, DepthReturn, StackFac))){
        //do
        //Pop(Next_Entry, S_Reversed);
        StackFac->Pop(Next_Entry, S_Reversed, StackFac);
        //Copy_Entry(Entry_Copy, Next_Entry);
        Copy_Entry(Entry_Copy, Next_Entry);
        //Push(Next_Entry, S_Orig);
        StackFac->Push(Next_Entry, S_Orig, StackFac);
        //Push(Entry_Copy, S_Copy);
        StackFac->Push(Entry_Copy, S_Copy, StackFac);
    }

    StackFac->TypeEntry->final(Next_Entry, StackFac->TypeEntry);
    StackFac->TypeEntry->final(Entry_Copy, StackFac->TypeEntry);
    StackFac->Stack->final(S_Reversed, StackFac->Stack);
    IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo);
}
Copy_Capability_for_Stack_Template* newObviousCCRealiz(void (*Copy_Entry)(r_type_ptr Entry, r_type_ptr Orig))
{
    Copy_Capability_for_Stack_Template* cc= calloc(1, sizeof(Copy_Capability_for_Stack_Template));
    cc->Copy_Stack = Copy_Stack;
    cc->OptionalParameters = Copy_Entry;
    return cc;
}
void freeObviousCCRealiz(Copy_Capability_for_Stack_Template* tofree)
{
    free(tofree);
}

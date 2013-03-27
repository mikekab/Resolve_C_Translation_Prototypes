/*
Realization Clean_Array_Realiz for Stack_Template;

    Definition Array_is_Clean(SR: Stack): B =
        For all i: Integer, if SR.Top < i <= Max_Depth
        then Entry.Is_Initial(SR.Contents(i));

    Type Stack is represented by Record
            Contents: Array 1..Max_Depth of Entry;
            Top: Integer;
        end;
        convention
            0 <= S.Top <= Max_Depth and Array_is_Clean(S);
        correspondence
            Conc.S = Reverse(Concatenation i: Z
            where 1 <= i <= S.Top, <S.Contents(i)>);

    Procedure Push(alters E: Entry; updates S: Stack);
        S.Top := S.Top + 1;
        E :=: S.Contents[S.Top];
    end Push;

    Procedure Pop(replaces R: Entry; updates S: Stack);
        Var Fresh_Val: Entry;

        R :=: S.Contents[S.Top];
        S.Contents[S.Top] :=: Fresh_Val;
        S.Top := S.Top - 1;
    end Pop;

    Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top;
    end Depth;

    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth - S.Top;
    end Rem_Capacity;

    Operation Clear_Entry(clears E: Entry);
    Procedure
		Var Temp: Entry;
		E :=: Temp;
    end Clear_Entry;

    Procedure Clear(clears S: Stack);
      While (S.Top > 0)
		changing S;
      	maintaining Array_is_Clean(S);
      	decreasing S.Top;
      do
        Clear_Entry(S.Contents[S.Top]);
        S.Top := S.Top - 1;
      end;
    end Clear;

end Clean_Array_Realiz;
*/
#include "Clean_Array_Realiz_rb.h"

typedef struct Stack_Instance
{
    r_type_ptr* Contents;
    r_type_ptr Top;
}Stack_Instance;
// init for the Stack type realized by Clean_Array_Realiz
// this is attached to a typeinfo struct named Stack
static r_type_ptr init_Stack(type_info* stackType)
{
    Stack_Template* ar = stackType->PointerToFacility;
    int numElems = IF->ValueOf(ar->MaxDepth);
    Stack_Instance* si = calloc(1, sizeof(Stack_Instance));
    si->Contents = CreateArrayOf(1, numElems, ar->TypeEntry);
    si->Top = IF->IntTypeInfo->init(IF->IntTypeInfo);
    Stack_Instance** t = malloc(sizeof(Stack_Instance*));
    *t = si;
    return (r_type_ptr)t;
}

static void final_Stack(r_type_ptr r, type_info* ti)
{
    Stack_Instance* SI = *r;
    Stack_Template* ar = ti->PointerToFacility;
    FreeArrayOf(ar->MaxDepth, SI->Contents, ar->TypeEntry);
    IF->IntTypeInfo->final(SI->Top, IF->IntTypeInfo);
    free(*r);
    free(r);
}



// local helper function
static type_info* newCleanArrayRealizStackTypeInfo()
{
    type_info* ti = calloc(1, sizeof(type_info));
    ti->init = init_Stack;
    ti->final = final_Stack;
    return ti;
}
/*
Procedure Push(alters E: Entry; updates S: Stack);
        S.Top := S.Top + 1;
        E :=: S.Contents[S.Top];
    end Push;
*/
static void Push(r_type_ptr E, r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    IF->Increment(SI->Top);
    swap(E,ArrayElementAt(SI->Top, SI->Contents));

}
/*
   Procedure Pop(replaces R: Entry; updates S: Stack);
        Var Fresh_Val: Entry;

        R :=: S.Contents[S.Top];
        S.Contents[S.Top] :=: Fresh_Val;
        S.Top := S.Top - 1;
    end Pop;
*/
static void Pop(r_type_ptr R, r_type_ptr S, Stack_Template* thisFac)
{
    r_type_ptr Fresh_Val = thisFac->TypeEntry->init(thisFac->TypeEntry);
    Stack_Instance* SI = *S;
    swap(R, ArrayElementAt(SI->Top, SI->Contents));
    swap(Fresh_Val,ArrayElementAt(SI->Top, SI->Contents));
    IF->Decrement(SI->Top);
    thisFac->TypeEntry->final(Fresh_Val, thisFac->TypeEntry);
}
/*
   Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top;
    end Depth;
*/
static r_type_ptr Depth(r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    return IF->CreateFromInteger(SI->Top);
}
/*
    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth - S.Top;
    end Rem_Capacity;
*/
static r_type_ptr Rem_Capacity(r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    r_type_ptr remcap = IF->IntTypeInfo->init(IF->IntTypeInfo);
    IF->Subtract(remcap, thisFac->MaxDepth, SI->Top);
    return remcap;
}
/*
    Operation Clear_Entry(clears E: Entry);
    Procedure
		Var Temp: Entry;
		E :=: Temp;
    end Clear_Entry;
*/
static void Clear_Entry(r_type_ptr E, Stack_Template* thisFac)
{
    r_type_ptr Temp = thisFac->TypeEntry->init(thisFac->TypeEntry);
    swap(E, Temp);

    thisFac->TypeEntry->final(Temp, thisFac->TypeEntry);
}
/*
    Procedure Clear(clears S: Stack);
      While (S.Top > 0)
		changing S;
      	maintaining Array_is_Clean(S);
      	decreasing S.Top;
      do
        Clear_Entry(S.Contents[S.Top]);
        S.Top := S.Top - 1;
      end;
    end Clear;
*/
static void Clear(r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    while(IF->ValueOf(SI->Top) > 0){
        Clear_Entry(ArrayElementAt(SI->Top, SI->Contents), thisFac);
        IF->Decrement(SI->Top);
    }
}

// Assigns values to the structure defined in the concept
extern Stack_Template* new_Clean_Array_Realiz_for_Stack_Template(type_info* TypeEntry, r_type_ptr MaxDepth)
{
    Stack_Template* ar = calloc(1, sizeof(Stack_Template));
    ar -> Push = Push;
    ar -> Pop = Pop;
    ar -> Clear = Clear;
    ar -> Depth = Depth;
    ar -> Rem_Capacity = Rem_Capacity;
    ar -> TypeEntry = TypeEntry;
    ar -> MaxDepth = IF->CreateFromInteger(MaxDepth);
    ar -> Stack = newCleanArrayRealizStackTypeInfo();
    ar -> Stack -> PointerToFacility = ar;
    return ar;
}

extern void free_Clean_Array_Realiz_for_Stack_Template(Stack_Template* toFree)
{
    free(toFree->Stack);
    IF->IntTypeInfo->final(toFree->MaxDepth, IF->IntTypeInfo);
    free(toFree);
}


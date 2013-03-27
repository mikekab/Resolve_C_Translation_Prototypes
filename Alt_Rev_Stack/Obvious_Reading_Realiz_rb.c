/*
Realization Obvious_Reading_Realiz (Operation Read_Entry(replaces E: Entry);)
		for Reading_Capability of Stack_Template;

	Procedure Read_upto(replaces S: Stack; preserves Count: Integer);
		Var Next_Entry: Entry;

		Clear(S);
		While (Depth(S) /= Count)
			changing S, Next_Entry;
			maintaining |S| <= Count;
			decreasing (Count - |S|);
		do
			Read_Entry(Next_Entry);
			Push(Next_Entry, S);
		end;
	end Read_upto;

	Procedure Read(replaces S: Stack);
		Read_upto(S, Max_Depth);
	end Read;
end Obvious_Reading_Realiz;
*/

#include "Obvious_Reading_Realiz_rb.h"
#include "Stack_Template_co.h"
#include "Integers.h"

static void Read_upto(r_type_ptr S, r_type_ptr Count, Reading_Capability_for_Stack_Template* thisFac)
{
    void (*Read_Entry)(r_type_ptr) = thisFac->OptionalParameters;
    r_type_ptr Next_Entry = thisFac->Enhanced_Template->TypeEntry->init(thisFac->Enhanced_Template->TypeEntry);
    thisFac->Enhanced_Template->Clear(S, thisFac->Enhanced_Template);
    r_type_ptr DepthReturn;

    while(IF->ValueOf(DepthReturn = thisFac->Enhanced_Template->Depth(S, thisFac->Enhanced_Template)) != IF->ValueOf(Count)){
        IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo);
        Read_Entry(Next_Entry);
        thisFac->Enhanced_Template->Push(Next_Entry, S, thisFac->Enhanced_Template);
    }
    IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo); // Free for when condition fails
    thisFac->Enhanced_Template->TypeEntry->final(Next_Entry, thisFac->Enhanced_Template->TypeEntry);
}
static void Read(r_type_ptr S, Reading_Capability_for_Stack_Template* thisFac)
{
    Read_upto(S, thisFac->Enhanced_Template->MaxDepth, thisFac);
}
extern Reading_Capability_for_Stack_Template* new_Obvious_Reading_Realiz_for_Reading_Capability_for_Stack_Template(void (*Read_Entry)(r_type_ptr),
                                                                                                                   Stack_Template* Enhanced_Template)
{
    Reading_Capability_for_Stack_Template* rc = calloc(1, sizeof(Reading_Capability_for_Stack_Template));
    rc->Read_upto = Read_upto;
    rc->Read = Read;
    rc->Enhanced_Template = Enhanced_Template;
    rc->OptionalParameters = Read_Entry;
    return rc;
}



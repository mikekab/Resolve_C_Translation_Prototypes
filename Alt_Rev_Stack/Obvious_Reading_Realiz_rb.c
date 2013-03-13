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

static void Read_upto(r_type_ptr S, Stack_Template* RealizToUse, r_type_ptr Count, Reading_Capability_for_Stack_Template* thisFac)
{
    void (*Read_Entry)(r_type_ptr) = thisFac->OptionalParameters;
    r_type_ptr Next_Entry = RealizToUse->TypeEntry->init(RealizToUse->TypeEntry);
    RealizToUse->Clear(S, RealizToUse);
    // Methods that return values in Resolve need a local placeholder
    // While Depth could be implemented as simply returning Top,
    // other operations such as Rem_Capacity require a new variable.
    r_type_ptr DepthReturn = IF->IntTypeInfo->init(IF->IntTypeInfo);
    RealizToUse->Depth(S, DepthReturn, RealizToUse);
    while( IF->ValueOf(DepthReturn) != IF->ValueOf(Count)){
        Read_Entry(Next_Entry);
        RealizToUse->Push(Next_Entry, S, RealizToUse);
        RealizToUse->Depth(S, DepthReturn, RealizToUse);
    }
    RealizToUse->TypeEntry->final(Next_Entry, RealizToUse->TypeEntry);
    IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo);
}
static void Read(r_type_ptr S, Stack_Template* RealizToUse, Reading_Capability_for_Stack_Template* thisFac)
{
    Read_upto(S, RealizToUse, RealizToUse->MaxDepth, thisFac);
}
extern Reading_Capability_for_Stack_Template* new_Obvious_Reading_Realiz_for_Reading_Capability_for_Stack_Template(void (*Read_Entry)(r_type_ptr))
{
    Reading_Capability_for_Stack_Template* rc = calloc(1, sizeof(Reading_Capability_for_Stack_Template));
    rc->Read_upto = Read_upto;
    rc->Read = Read;
    rc->OptionalParameters = Read_Entry;
    return rc;
}



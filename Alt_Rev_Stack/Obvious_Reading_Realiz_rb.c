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

static void Read_upto(r_type_ptr S, Stack_Template* RealizToUse, r_type_ptr Count)
{
    Integer_Fac* IF = newIntegerFac();
    r_type_ptr Next_Entry = RealizToUse->TypeEntry->init(RealizToUse);
    RealizToUse->Clear(S);
    while( IF->ValueOf(RealizToUse->Depth(S)) != IF->ValueOf(Count)){
        RealizToUse->TypeEntry->Read(Next_Entry);
        RealizToUse->Push(Next_Entry, S);
    }

}
static void Read(r_type_ptr S, Stack_Template* RealizToUse)
{
    Read_upto(S, RealizToUse, RealizToUse->MaxDepth);
}
extern Reading_Capability_for_Stack_Template* newReading_Capability_for_Stack_Template()
{
    Reading_Capability_for_Stack_Template* rc = calloc(1, sizeof(Reading_Capability_for_Stack_Template));
    rc->Read_upto = Read_upto;
    rc->Read = Read;
    return rc;
}



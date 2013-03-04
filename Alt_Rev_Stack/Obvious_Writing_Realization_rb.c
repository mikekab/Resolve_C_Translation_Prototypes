/*
Realization Obvious_Writing_Realiz (Operation Write_Entry(evaluates E: Entry);)
		for Writing_Capability of Stack_Template;

	Procedure Write(clears S: Stack);
		Var Next_Entry: Entry;

		While (Depth(S) /= 0)
			changing S, Next_Entry;
			maintaining true;
			decreasing |S|;
		do
			Pop(Next_Entry, S);
			Write_Entry(Next_Entry);
		end;
	end Write;
end Obvious_Writing_Realiz;
*/
#include "Obvious_Writing_Realization_rb.h"
#include "Integers.h"
static void Write(r_type_ptr S, Stack_Template* RealizToUse)
{
    Integer_Fac* IF = newIntegerFac();
    r_type_ptr Next_Entry = RealizToUse->TypeEntry->init(RealizToUse);
    while( IF->ValueOf(RealizToUse->Depth(S)) != 0){
        RealizToUse->Pop(Next_Entry, S);
        RealizToUse->TypeEntry->Write(Next_Entry);

    }
}

extern Writing_Capability_for_Stack_Template* newWriting_Capability_for_Stack_Template()
{
    Writing_Capability_for_Stack_Template* wc = calloc(1, sizeof(Writing_Capability_for_Stack_Template));
    wc->Write = Write;
    return wc;
}


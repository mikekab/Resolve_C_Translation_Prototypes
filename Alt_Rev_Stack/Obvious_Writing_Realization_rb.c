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
static void Write(r_type_ptr S, Stack_Template* RealizToUse, Writing_Capability_for_Stack_Template* thisFac)
{
    r_type_ptr Next_Entry = RealizToUse->TypeEntry->init(RealizToUse->TypeEntry);
    void (*Write_Entry)(r_type_ptr) = thisFac->OptionalParams;
    // Methods that return values in Resolve need a local placeholder
    // While Depth could be implemented as simply returning Top,
    // other operations such as Rem_Capacity require a new variable.
    r_type_ptr DepthReturn = IF->IntTypeInfo->init(IF->IntTypeInfo);

    while( IF->ValueOf(RealizToUse->Depth(S, DepthReturn, RealizToUse)) != 0){
        RealizToUse->Pop(Next_Entry, S, RealizToUse);

        Write_Entry(Next_Entry);
    }
    RealizToUse->TypeEntry->final(Next_Entry, RealizToUse->TypeEntry);
    IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo);
}

extern Writing_Capability_for_Stack_Template* new_Obvious_Writing_Realiz_for_Writing_Capability_for_Stack_Template(void (*Write_Entry)(r_type_ptr))
{
    Writing_Capability_for_Stack_Template* wc = calloc(1, sizeof(Writing_Capability_for_Stack_Template));
    wc->Write = Write;
    wc->OptionalParams = Write_Entry;
    return wc;
}


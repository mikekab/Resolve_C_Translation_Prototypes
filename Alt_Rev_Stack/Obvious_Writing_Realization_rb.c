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
static void Write(r_type_ptr S, Writing_Capability_for_Stack_Template* thisFac)
{
    r_type_ptr Next_Entry = thisFac->Enhanced_Template->TypeEntry->init(thisFac->Enhanced_Template->TypeEntry);
    void (*Write_Entry)(r_type_ptr) = thisFac->OptionalParams;
    r_type_ptr DepthReturn;

    while(IF->ValueOf(DepthReturn = thisFac->Enhanced_Template->Depth(S, thisFac->Enhanced_Template)) != 0){
        IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo);
        thisFac->Enhanced_Template->Pop(Next_Entry, S, thisFac->Enhanced_Template);

        Write_Entry(Next_Entry);
    }
    IF->IntTypeInfo->final(DepthReturn, IF->IntTypeInfo); // Free for when condition fails
    thisFac->Enhanced_Template->TypeEntry->final(Next_Entry, thisFac->Enhanced_Template->TypeEntry);
}

extern Writing_Capability_for_Stack_Template* new_Obvious_Writing_Realiz_for_Writing_Capability_for_Stack_Template(void (*Write_Entry)(r_type_ptr),
                                                                                                                    Stack_Template* Enhanced_Template)
{
    Writing_Capability_for_Stack_Template* wc = calloc(1, sizeof(Writing_Capability_for_Stack_Template));
    wc->Write = Write;
    wc->Enhanced_Template = Enhanced_Template;
    wc->OptionalParams = Write_Entry;
    return wc;
}


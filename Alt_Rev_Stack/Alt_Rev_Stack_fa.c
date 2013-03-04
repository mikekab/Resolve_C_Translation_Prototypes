/*
-- an example of a stack with an enhancement and read/write
*/
/*
Facility Alt_Rev_Stack;
    Facility Stack_Fac is Stack_Template(Integer, 4)
    	    realized by Array_Realiz
    	enhanced by Reading_Capability
	        realized by Obvious_Reading_Realiz(Std_Integer_Fac.Read)
	    enhanced by Writing_Capability
	        realized by Obvious_Writing_Realiz (Std_Integer_Fac.Write);

    Facility StackStackFac is Stack_Template(Stack_Template.Stack, 2)
        realized by Array_Realiz;
*/

#include "Stack_Template_co.h"
#include "Array_Realiz_rb.h"
#include "Obvious_Reading_Realiz_rb.h"
#include "Obvious_Writing_Realization_rb.h"

typedef struct stack_Fac
{
    Stack_Template* core;
    Reading_Capability_for_Stack_Template* read_enhancement;
    Writing_Capability_for_Stack_Template* write_enhancement;
    Integer_Fac* IF;
} stack_Fac;

int main()
{
    stack_Fac Stack_Fac;
    Integer_Fac* IF = newIntegerFac(0);
    Stack_Fac.IF = IF;

    r_type_ptr stackfacdepth = IF->IntTypeInfo->init(IF);
    IF->AssignLiteral(stackfacdepth, 4);
    Stack_Fac.core = new_Array_Realiz(IF->IntTypeInfo,IF, stackfacdepth);
    Stack_Fac.read_enhancement = newReading_Capability_for_Stack_Template();
    Stack_Fac.write_enhancement = newWriting_Capability_for_Stack_Template();

    r_type_ptr stackstackfacdepth = IF->IntTypeInfo->init(IF);
    IF->AssignLiteral(stackstackfacdepth, 2);
    Stack_Template* StackStackFac = new_Array_Realiz(Stack_Fac.core->Stack, Stack_Fac.core, stackstackfacdepth);

/*
    Operation Main();
    Procedure
        Var SS: StackStackFac.Stack;
        Var S1, S2: Stack_Fac.Stack;
        Read(S1);
        Read(S2);
        Push(S1, SS);
        Push(S2, SS);
	    Write_Line("REVERSED ORDER");
	    Pop(S1, SS);
	    Write(S1);
	    Pop(S1, SS);
        Write(S1);
    end Main;

end Alt_Rev_Stack;
*/
    r_type_ptr SS = StackStackFac->Stack->init(StackStackFac);
    r_type_ptr S1 = Stack_Fac.core->Stack->init(Stack_Fac.core);
    r_type_ptr S2 = Stack_Fac.core->Stack->init(Stack_Fac.core);

    Stack_Fac.read_enhancement->Read(S1, Stack_Fac.core);
    Stack_Fac.read_enhancement->Read(S2, Stack_Fac.core);

    StackStackFac->Push(S1, SS);
    StackStackFac->Push(S2, SS);

    printf("REVERSED ORDER\n");
    StackStackFac->Pop(S1, SS);
    Stack_Fac.write_enhancement->Write(S1, Stack_Fac.core);
    StackStackFac->Pop(S1, SS);
    Stack_Fac.write_enhancement->Write(S1, Stack_Fac.core);

    return 0;
}

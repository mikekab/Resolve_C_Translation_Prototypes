/*
Facility Alt_Rev_Stack;
*/

#include "Resolve.h"
#include "Integers.h"
#include "Stack_Template_co.h"
#include "Array_Realiz_rb.h"
#include "Clean_Array_Realiz_rb.h"
#include "Obvious_Reading_Realiz_rb.h"
#include "Obvious_Writing_Realization_rb.h"


typedef struct stack_Fac
{
    Stack_Template* core;
    Reading_Capability_for_Stack_Template* read_enhancement;
    Writing_Capability_for_Stack_Template* write_enhancement;
} stack_Fac;

int main()
{
    IF = newIntegerFac(0); // IF is the global integer fac, 0 is the initial value.
    stack_Fac Stack_Fac;

    r_type_ptr depth = IF->CreateFrom_int(4);

    /*
    Facility Stack_Fac is Stack_Template(Integer, 4)
    	    realized by Array_Realiz
    */
    Stack_Fac.core = new_Array_Realiz_for_Stack_Template(IF->IntTypeInfo, depth);
    /*
        enhanced by Reading_Capability
	        realized by Obvious_Reading_Realiz(Std_Integer_Fac.Read)
    */
    Stack_Fac.read_enhancement = new_Obvious_Reading_Realiz_for_Reading_Capability_for_Stack_Template(IF->Read, Stack_Fac.core);
    /*
        enhanced by Writing_Capabilit
	        realized by Obvious_Writing_Realiz (Std_Integer_Fac.Write);
    */
    Stack_Fac.write_enhancement = new_Obvious_Writing_Realiz_for_Writing_Capability_for_Stack_Template(IF->Write, Stack_Fac.core);

    IF->AssignLiteral(depth, 2);

    /*
    Facility StackStackFac is Stack_Template(Stack_Template.Stack, 2)
        realized by Array_Realiz;
    */
    Stack_Template* StackStackFac = new_Clean_Array_Realiz_for_Stack_Template(Stack_Fac.core->Stack, depth);

/*
    Operation Main();
    Procedure
*/
    // Var SS: StackStackFac.Stack;
    r_type_ptr SS = StackStackFac->Stack->init(StackStackFac->Stack);

    // Var S1, S2: Stack_Fac.Stack;
    r_type_ptr S1 = Stack_Fac.core->Stack->init(Stack_Fac.core->Stack);
    r_type_ptr S2 = Stack_Fac.core->Stack->init(Stack_Fac.core->Stack);

    // Read(S1)
    Stack_Fac.read_enhancement->Read(S1, Stack_Fac.read_enhancement);

    // Read(S2)
    Stack_Fac.read_enhancement->Read(S2, Stack_Fac.read_enhancement);

    // Push(S1, SS)
    StackStackFac->Push(S1, SS, StackStackFac);
    // Push(S2, SS)
    StackStackFac->Push(S2, SS, StackStackFac);
    // Write_Line("REVERSED ORDER");
    printf("REVERSED ORDER\n");
    // Pop(S1, SS);
    StackStackFac->Pop(S1, SS, StackStackFac);
    // Write(S1)
    Stack_Fac.write_enhancement->Write(S1, Stack_Fac.write_enhancement);
    // Pop(S1, SS);
    StackStackFac->Pop(S1, SS, StackStackFac);
    // Write(S1);
    Stack_Fac.write_enhancement->Write(S1, Stack_Fac.write_enhancement);


    // Freeing dynamically created locals
    Stack_Fac.core->Stack->final(S1, Stack_Fac.core->Stack);
    Stack_Fac.core->Stack->final(S2, Stack_Fac.core->Stack);
    StackStackFac->Stack->final(SS, StackStackFac->Stack);
    IF->IntTypeInfo->final(depth, IF->IntTypeInfo );
    free_Array_Realiz_for_Stack_Template(Stack_Fac.core);
    free(Stack_Fac.read_enhancement);
    free(Stack_Fac.write_enhancement);
    free_Clean_Array_Realiz_for_Stack_Template(StackStackFac);
    free_Integer_Fac(IF);
    return 0;
    // end Main;
}
// end Alt_Rev_Stack;

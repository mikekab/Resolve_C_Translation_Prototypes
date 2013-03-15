/*
-- example of a stack of Integers that has a copy enhancement and can be printed
-- a key point is that the copy shows how to pass an operation as a parameter
Facility CopyStack;
    Operation Copy_Integer(replaces C: Integer; restores Orig: Integer);
        ensures C = Orig;
      Procedure
        C := Replica(Orig);
    end Copy_Integer;

    Facility Copy_Stack_Fac is Stack_Template(Integer, 5)
            realized by Array_Realiz
        enhanced by Copy_Capability
            realized by Obvious_CC_Realiz(Copy_Integer)
        enhanced by Writing_Capability
            realized by Obvious_Writing_Realiz(Std_Integer_Fac.Write);

    Operation Main();
    Procedure
        Var S1, S2: Stack;
        Var I: Integer;

        I := 47;
        Push(I, S1);
        I := 53;
        Push(I, S1);
        I := 59;
        Push(I, S1);
        Write(S1);

        Copy_Stack(S2,S1);
        Write_Line("");
        Write(S1);
        Write_Line("");
        Write(S2);

    end Main;

end CopyStack;
*/
#include "Resolve.h"
#include "Integers.h"
#include "Array_Realiz_rb.h"
#include "Obvious_CC_Realiz_rb.h"
#include "Obvious_Writing_Realization_rb.h"
/*
    Operation Copy_Integer(replaces C: Integer; restores Orig: Integer);
        ensures C = Orig;
      Procedure
        C := Replica(Orig);
    end Copy_Integer;
*/

void Copy_Integer(r_type_ptr C, r_type_ptr Orig)
{
    // Freeing C so that it does not leak
    IF->IntTypeInfo->final(C, IF->IntTypeInfo);
    C = IF->Replica(Orig);
}


typedef struct _Copy_Stack_Fac
{
    Stack_Template* core;
    Copy_Capability_for_Stack_Template* copy_enhancement;
    Writing_Capability_for_Stack_Template* write_enhancement;
} _Copy_Stack_Fac;

int main()
{
    IF = newIntegerFac(0);
    //Facility Copy_Stack_Fac is Stack_Template(Integer, 5)
    //        realized by Array_Realiz
    r_type_ptr coreMaxDepth = IF->IntTypeInfo->init(IF->IntTypeInfo);
    IF->AssignLiteral(coreMaxDepth, 5);
    _Copy_Stack_Fac Copy_Stack_Fac;
    Copy_Stack_Fac.core = new_Array_Realiz(IF->IntTypeInfo, coreMaxDepth);
    //    enhanced by Copy_Capability
    //        realized by Obvious_CC_Realiz(Copy_Integer)
    Copy_Stack_Fac.copy_enhancement = newObviousCCRealiz(Copy_Integer);
    //    enhanced by Writing_Capability
    //        realized by Obvious_Writing_Realiz(Std_Integer_Fac.Write);
    Copy_Stack_Fac.write_enhancement = new_Obvious_Writing_Realiz_for_Writing_Capability_for_Stack_Template(IF->Write);

        //Operation Main();
    //Procedure
        //Var S1, S2: Stack;
        r_type_ptr S1 = Copy_Stack_Fac.core->Stack->init(Copy_Stack_Fac.core->Stack);
        r_type_ptr S2 = Copy_Stack_Fac.core->Stack->init(Copy_Stack_Fac.core->Stack);
        //Var I: Integer;
        r_type_ptr I = IF->IntTypeInfo->init(IF->IntTypeInfo);
        //I := 47;
        IF->AssignLiteral(I, 47);
        //Push(I, S1);
        Copy_Stack_Fac.core->Push(I, S1, Copy_Stack_Fac.core);
        //I := 53;
        IF->AssignLiteral(I, 53);
        //Push(I, S1);
        Copy_Stack_Fac.core->Push(I, S1, Copy_Stack_Fac.core);
        //I := 59;
        IF->AssignLiteral(I, 59);
        //Push(I, S1);
        Copy_Stack_Fac.core->Push(I, S1, Copy_Stack_Fac.core);
        //Write(S1);
        Copy_Stack_Fac.write_enhancement->Write(S1, Copy_Stack_Fac.core, Copy_Stack_Fac.write_enhancement);

        //Copy_Stack(S2,S1);
        Copy_Stack_Fac.copy_enhancement->Copy_Stack(S2, S1, Copy_Stack_Fac.core, Copy_Stack_Fac.copy_enhancement);
        //Write_Line("");
        printf("\n");
        //Write(S1);
        Copy_Stack_Fac.write_enhancement->Write(S1, Copy_Stack_Fac.core, Copy_Stack_Fac.write_enhancement);
        //Write_Line("");
        printf("\n");
        //Write(S2);
        Copy_Stack_Fac.write_enhancement->Write(S2, Copy_Stack_Fac.core, Copy_Stack_Fac.write_enhancement);

        Copy_Stack_Fac.core->Stack->final(S1, Copy_Stack_Fac.core->Stack);
        Copy_Stack_Fac.core->Stack->final(S2, Copy_Stack_Fac.core->Stack);
        free_Array_Realiz(Copy_Stack_Fac.core);
        freeObviousCCRealiz(Copy_Stack_Fac.copy_enhancement);
        free_Obvious_Writing_Realiz_for_Writing_Capability_for_Stack_Template(Copy_Stack_Fac.write_enhancement);
        IF->IntTypeInfo->final(coreMaxDepth, IF->IntTypeInfo);
        IF->IntTypeInfo->final(I, IF->IntTypeInfo);
        freeIntegerFac(IF);
//    end Main;
    return 0;
}

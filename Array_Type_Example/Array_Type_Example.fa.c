#include <stdlib.h>
#include "../Common/Integers.h"

/*
-- Example of a local array type
Facility Array_Type_Example;


    Type Example = Array 1..50 of Integer;
    Type Example2 = Array 1..100 of Integer;
*/

    Integer* Type_Example()
    {
        return calloc(50,sizeof(Integer));
    }

    Integer* Type_Example2()
    {

        return calloc(100,sizeof(Integer));
    }

//    Operation Main();
//    Procedure
    int main()
    {
        //Var A: Example;
        //Var C : Example2;
        Integer* A = Type_Example();
        Integer* C = Type_Example2();
        // Var I, J, K: Integer;
        Integer_Fac* IF = newIntegerFac();
        Integer I, J, K;
        //I := 17;
        I = 17;
        //J := 27;
        J = 27;
        //I->Write(I);
        IF->Write(I);
        //Write(J);
        IF->Write(J);
        //A[3] :=: I;
        IF->Swap(&(A[3]), &I);
        //J :=: A[3];
        IF->Swap(&J, &(A[3]));
        //K :=: A[3];
        IF->Swap(&K, &(A[3]));
        //Write(J);
        IF->Write(J);
        //Write(K);
        IF->Write(K);
        free(A);
        free(C);
        free(IF);
        return 0;
        // end Main;
    }
//end Array_Type_Example;




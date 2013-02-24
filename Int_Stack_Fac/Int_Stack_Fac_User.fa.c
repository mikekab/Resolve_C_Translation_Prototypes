/*
Facility Int_Stack_Fac_User;
    uses Int_Stack_Fac;
    Operation Main();
    Procedure
        Var S: Stack;
        Var Temp: Integer;
        Init(S);
        Temp := 1;
        Push(Temp, S);
        Temp := 2;
        Push(Temp, S);
        Pop(Temp, S);
        Write(Temp);
        Pop(Temp, S);
        Write(Temp);
        -- Writes 21
    end Main;
end Int_Stack_Fac_User;
*/
#include "../Common/Integers.h"
#include "Int_Stack_Fac.fa.h" // separately compiled short facility

int main()
{
    Integer_Fac* IF = newIntegerFac(); // declared in Integers.h

    /*
        Int_Stack_Fac is a typedef'd struct defined in Int_Stack_Fac.fa.h.
        Fields of this struct are function pointers to functions
        that operate on Stack types.  newIntStackFac() allocates
        memory for the struct and returns a pointer to it.
    */
    Int_Stack_Fac* ISF = newIntStackFac();
    /*
        Stack is a typedef'd struct defined in Int_Stack_Fac.fa.h
        Fields of this struct are member variables of the Stack
        type (an array of integers and a top integer).  Type_Stack()
        allocates memory for the struct and returns a pointer to it.
    */
    Stack* S = Type_Stack();

    Integer Temp;
    ISF->Init(S);
    Temp = 1;
    ISF->Push(&Temp, S, IF);
    Temp = 2;
    ISF->Push(&Temp, S, IF);
    ISF->Pop(&Temp, S, IF);
    IF->Write(Temp);
    ISF->Pop(&Temp, S, IF);
    IF->Write(Temp);
    free(ISF);
    free(IF);
    free(S);
    return 0;
    // prints 21
}

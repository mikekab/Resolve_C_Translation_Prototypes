#include "Int_Stack_Fac.fa.h"
extern Stack* Type_Stack(){return calloc(1, sizeof(Stack));}
/*
   Operation Init(updates S: Stack);
    Procedure
        S.Top := 0;
    end Init;
*/
static void Init(Stack* S)
{
    S->Top = -1;
}


/*
    Operation Push(alters I: Integer; updates S: Stack);
    Procedure
        S.Top := S.Top + 1;
        S.Contents[S.Top] :=: I;
    end Push;
*/

// Integer_Fac* is passed as a parameter for the 
// swap functionality.
static void Push(Integer* I, Stack* S, Integer_Fac* IF)
{
    S->Top = S->Top + 1;
    IF->Swap(I, &(S->Contents[S->Top]));
}
/*
    Operation Pop(replaces I: Integer; updates S: Stack);
    Procedure
        I :=: S.Contents[S.Top];
        S.Top := S.Top - 1;
    end Pop;
*/
static void Pop(Integer* I, Stack* S, Integer_Fac* IF)
{
    IF->Swap(I, &(S->Contents[S->Top]));
    S->Top = S->Top - 1;
}

// Since this file is separately compiled, the procedures
// above are only made visible through the following
// function.
extern Int_Stack_Fac* newIntStackFac()
{
    Int_Stack_Fac* newStackFac = calloc(1, sizeof(Int_Stack_Fac));
    newStackFac->Init = Init;
    newStackFac->Push = Push;
    newStackFac->Pop  = Pop;
    return newStackFac;
}

// Example of a compiled short facility

/*
Facility Int_Stack_Fac;
Type Stack = Record
        Contents: Array 1..100 of Integer;
        Top: Integer;
    end;

    Operation Init(updates S: Stack);
    Procedure
        S.Top := 0;
    end Init;

    Operation Push(alters I: Integer; updates S: Stack);
    Procedure
        S.Top := S.Top + 1;
        S.Contents[S.Top] :=: I;
    end Push;
end Int_Stack_Fac;
*/
#ifndef __INT_STACK_FAC_FA_H
#define __INT_STACK_FAC_FA_H

#include "../Common/Integers.h"
typedef struct Stack_Instance
{
    Integer Contents[100];
    Integer Top;
}Stack;

// Returns a new set of member variables.
// Many instances of Stack can use the same set of procedures.
extern Stack* Type_Stack();

typedef struct Int_Stack_Fac_Procedures
{
    void(*Init)(Stack*);
    void(*Push)(Integer*, Stack*, Integer_Fac*);
    void(*Pop)(Integer*, Stack*, Integer_Fac*);
}Int_Stack_Fac;

// Returns a new set of procedures.  Only one
// instance of this is needed.
extern Int_Stack_Fac* newIntStackFac();
#endif

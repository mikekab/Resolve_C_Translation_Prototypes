#ifndef __INTEGERS_H
#define __INTEGERS_H

#include <stdlib.h>
#include <stdio.h>


typedef int Integer;

// Not storing function pointers for each Integer
// cuts memory requirements
typedef struct Integer_Funcs{
    void (*Write)(Integer);
    void (*Read)(Integer*);
    void (*Swap)(Integer*, Integer*);
}Integer_Fac;

extern Integer_Fac* newIntegerFac();

#endif




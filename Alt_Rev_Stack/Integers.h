#ifndef __INTEGERS_H
#define __INTEGERS_H

#include <stdlib.h>
#include <stdio.h>
#include "Resolve.h"




// Not storing function pointers for each Integer
// cuts memory requirements
typedef struct Integer_Funcs{
    void (*AssignLiteral)(r_type_ptr, int);
    int (*ValueOf)(r_type_ptr);
    void (*Increment)(r_type_ptr);
    void (*Decrement)(r_type_ptr);
    int defaultValue;
    type_info* IntTypeInfo;
}Integer_Fac;

extern Integer_Fac* newIntegerFac();

extern type_info* newIntTypeInfo();
#endif





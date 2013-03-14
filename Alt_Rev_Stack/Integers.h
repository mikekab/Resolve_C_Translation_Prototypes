#ifndef __INTEGERS_H
#define __INTEGERS_H

#include <stdlib.h>
#include <stdio.h>
#include "Resolve.h"


typedef struct Integer_Funcs{
    void (*AssignLiteral)(r_type_ptr, int);
    int (*ValueOf)(r_type_ptr);
    void (*Copy)(r_type_ptr, r_type_ptr);
    void (*Increment)(r_type_ptr);
    void (*Decrement)(r_type_ptr);
    void (*Add)(r_type_ptr, r_type_ptr, r_type_ptr);
    void (*Subtract)(r_type_ptr, r_type_ptr, r_type_ptr);
    void (*Read)(r_type_ptr);
    void (*Write)(r_type_ptr);
    int defaultValue;
    type_info* IntTypeInfo;
}Integer_Fac;

// globally accessible integer facility
// IF = newIntegerFac(0); will appear at the beginning of the main function
Integer_Fac* IF;
extern Integer_Fac* newIntegerFac(int);

#endif





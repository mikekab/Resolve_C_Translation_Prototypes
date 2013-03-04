
#include <stdlib.h>
#include <stdio.h>
#include "Integers.h"

static void Write(r_type_ptr I)
{
    int ** t = I;
    printf("%d", **t);
}
static void Read(r_type_ptr I)
{
    int * t = *I;
    scanf("%d", t);
}
static r_type_ptr init (Integer_Fac* IF)
{
    int* t = calloc(1,sizeof(int));
    *t = IF->defaultValue;
    int** u = malloc(sizeof(int*));
    *u = t;
    return (r_type_ptr)u;
}
static void AssignLiteral(r_type_ptr r, int v)
{
    **(int**)r = v;
}
static int ValueOf(r_type_ptr r)
{
    return **(int**)r;
}
static void Increment(r_type_ptr r)
{
    **(int**)r = **(int**)r + 1;
}
static r_type_ptr* CreateArrayOf(unsigned int s, Integer_Fac* IF)
{
    r_type_ptr* a= calloc(s, sizeof(r_type_ptr));
    int i;
    for(i = 0; i < s; ++i){
        a[i] = init(IF);
    }
    return a;
}
static void Decrement(r_type_ptr r)
{
    **(int**)r = **(int**)r - 1;
}
static void final (r_type_ptr r)
{
    free(*r);
}
extern Integer_Fac* newIntegerFac(int defaultValue)
{
    Integer_Fac* I = malloc(sizeof(Integer_Fac));
    I -> AssignLiteral = AssignLiteral;
    I -> ValueOf = ValueOf;
    I -> Increment = Increment;
    I -> Decrement = Decrement;
    I -> defaultValue = defaultValue;
    I -> IntTypeInfo = newIntTypeInfo(NULL);
    return I;
}

extern type_info* newIntTypeInfo(void* ignored)
{
    type_info* pc = calloc(1, sizeof(type_info));
    pc->init = init;
    pc->final = final;
    pc->CreateArrayOf = CreateArrayOf;
    pc->Read = Read;
    pc->Write = Write;
    return pc;
}



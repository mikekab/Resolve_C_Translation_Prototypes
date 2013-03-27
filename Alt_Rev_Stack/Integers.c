
#include <stdlib.h>
#include <stdio.h>
#include "Integers.h"

static void Write(r_type_ptr I)
{
    printf("%d", **(int**)I);
}
static void Read(r_type_ptr I)
{
    scanf("%d", *(int**)I);
}
static r_type_ptr init (type_info* ti)
{
    int* t = calloc(1,sizeof(int));
    Integer_Fac* intfac = ti->PointerToFacility;
    *t = intfac->defaultValue;
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
static void Copy(r_type_ptr source, r_type_ptr destination)
{
    **(int**)destination = **(int**)source;
}
static void Increment(r_type_ptr r)
{
    **(int**)r = **(int**)r + 1;
}

static void Decrement(r_type_ptr r)
{
    **(int**)r = **(int**)r - 1;
}

static void Add(r_type_ptr Result, r_type_ptr A, r_type_ptr B)
{
    **(int**)Result = **(int**)A + **(int**)B ;
}

static void Subtract(r_type_ptr Result, r_type_ptr A, r_type_ptr B)
{
    **(int**)Result = **(int**)A - **(int**)B ;
}
static r_type_ptr CreateFrom_int(int I)
{
    r_type_ptr newInt = IF->IntTypeInfo->init(IF->IntTypeInfo);
    IF->AssignLiteral(newInt, I);
    return newInt;
}
static r_type_ptr CreateFromInteger(r_type_ptr I)
{
    r_type_ptr newInt = IF->IntTypeInfo->init(IF->IntTypeInfo);
    IF->Copy(I, newInt);
    return newInt;
}
static void final (r_type_ptr r, type_info* ti)
{
    free(*r);
    free(r);
}

static type_info* newIntTypeInfo()
{
    type_info* pc = calloc(1, sizeof(type_info));
    pc->init = init;
    pc->final = final;
    return pc;
}

extern Integer_Fac* newIntegerFac(int defaultValue)
{
    Integer_Fac* I = malloc(sizeof(Integer_Fac));
    I -> AssignLiteral = AssignLiteral;
    I -> CreateFrom_int = CreateFrom_int;
    I -> CreateFromInteger = CreateFromInteger;
    I -> ValueOf = ValueOf;
    I -> Copy = Copy;
    I -> Increment = Increment;
    I -> Decrement = Decrement;
    I -> Add = Add;
    I -> Subtract = Subtract;
    I -> Read = Read;
    I -> Write = Write;
    I -> defaultValue = defaultValue;
    I -> IntTypeInfo = newIntTypeInfo();
    I -> IntTypeInfo -> PointerToFacility = I;
    return I;
}

extern void free_Integer_Fac(Integer_Fac* toFree)
{
    free(toFree->IntTypeInfo);
    free(toFree);
}



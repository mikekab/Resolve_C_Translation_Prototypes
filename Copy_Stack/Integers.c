
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
static void Assign(r_type_ptr source, r_type_ptr destination)
{
    **(int**)destination = **(int**)source;
}
static r_type_ptr Replica(r_type_ptr orig)
{
    int* t = calloc(1,sizeof(int));
    *t = **(int**)orig;
    int** u = malloc(sizeof(int*));
    *u = t;
    return (r_type_ptr)u;
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
    I -> ValueOf = ValueOf;
    I -> Assign = Assign;
    I -> Replica = Replica;
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

extern void freeIntegerFac(Integer_Fac* tofree)
{
    free(tofree->IntTypeInfo);
    free(tofree);
}




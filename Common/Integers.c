
#include <stdlib.h>
#include <stdio.h>
#include "Integers.h"

static void Write(Integer I)
{
    printf("%d", I);
}
static void Read(Integer* I)
{
    scanf("%d", I);
}
static void Swap(Integer* A, Integer* B)
{
    Integer temp = *A;
    *A = *B;
    *B = temp;
}
extern Integer_Fac* newIntegerFac()
{
    Integer_Fac* I = malloc(sizeof(Integer_Fac));
    I -> Write = Write;
    I -> Read = Read;
    I -> Swap = Swap;
    return I;
}


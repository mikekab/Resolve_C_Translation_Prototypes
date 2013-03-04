#ifndef __COMMON_H
#define __COMMON_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

typedef void* rtype;
typedef rtype* r_type_ptr;

typedef struct type_info
{
    r_type_ptr (*init)(void* PointerToFacility);
    void (*final)(r_type_ptr);
    r_type_ptr* (*CreateArrayOf)();
    void (*Read)(r_type_ptr);
    void (*Write)(r_type_ptr);
}type_info;

void swap(r_type_ptr A, r_type_ptr B);

#endif

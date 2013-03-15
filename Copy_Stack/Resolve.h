#ifndef __RESOLVE_H
#define __RESOLVE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

typedef void* rtype;
typedef rtype* r_type_ptr;
typedef struct type_info type_info;

/* Universal interface for resolve types.  This interface allows
    initalization and finalization of objects without requiring those
    objects to have any method pointers.  Of course this requires matching
    type_info's to objects of their type.  Type_info pointers are passed
    as parameters to methods when generic type manipulation is needed.
    The fields are assigned values when realizations are created.  The
    type_info is itself a field of a particular realization.

    Inside the init function the PointerToFacility element can be properly
    cast to the correct type.  For example..

    static r_type_ptr init_Stack(type_info* stackType)
    {
        Stack_Template* ar = stackType->PointerToFacility;
        .....
    }
*/
struct type_info
{
    r_type_ptr (*init)(type_info* thisType);
    void (*final)(r_type_ptr, type_info* thisType);
    void* PointerToFacility;
};

// Globally accesible methods
extern void swap(r_type_ptr A, r_type_ptr B);
extern r_type_ptr* CreateArrayOf(unsigned int start, unsigned int end, type_info* ti);
extern void FreeArrayOf(r_type_ptr Depth, r_type_ptr* array, type_info* ti);
extern r_type_ptr ArrayElementAt(r_type_ptr index, r_type_ptr* array);

#endif

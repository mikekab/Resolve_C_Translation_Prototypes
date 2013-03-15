#include "Resolve.h"
#include "Integers.h"

// Global functions

extern void swap(r_type_ptr A, r_type_ptr B){
  void* temp = *A;

  *A = *B;
  *B = temp;
}

// Creates a fully initialized array of any resolve type
// Array 1..Max_Depth of Entry; results in a call to this function
// with these params: CreateArrayOf(1, IF->ValueOF(Max_Depth), type_info* for Entry);
extern r_type_ptr* CreateArrayOf(unsigned int start, unsigned int end, type_info* ti)
{
    // start offset is stored as first element
    // (Resolve allows arrays with different start indices)
    unsigned int numElems = end - start + 2;
    r_type_ptr* a= calloc(numElems, sizeof(r_type_ptr));
    int i;
    a[0] = IF->IntTypeInfo->init(IF->IntTypeInfo);
    IF->AssignLiteral(a[0], start);

    for(i = 1; i < numElems; ++i){
        a[i] = ti->init(ti);
    }
    return a;
}

// First this calls the final method of each element
// then it frees the array of pointers.
extern void FreeArrayOf(r_type_ptr Depth, r_type_ptr* array, type_info* ti)
{
    IF->IntTypeInfo->final((r_type_ptr)array[0], IF->IntTypeInfo);
    int i;
    int d = IF->ValueOf(Depth);
    for (i = 1; i <= d; ++i){
        ti->final(array[i], ti);
    }
    free(array);
}
// returns the value stored at index, adjusting for the offset
extern r_type_ptr ArrayElementAt(r_type_ptr index, r_type_ptr* array)
{
    unsigned int reqIndex = IF->ValueOf(index) - IF->ValueOf(array[0]) + 1;
    // 1 is added since the first element is not part of the array data
    return array[reqIndex];
}

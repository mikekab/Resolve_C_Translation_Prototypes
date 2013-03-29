
#include "Static_Array_Template_co.h"
#include "Integers.h"


static r_type_ptr init_Static_Array_Instance(type_info* ti)
{
    // Initialize the array
    Static_Array_Template* thisRealiz = ti->PointerToFacility;
    int start = IF->ValueOf(thisRealiz->Lower_Bound);
    int end = IF->ValueOf(thisRealiz->Upper_Bound);

    unsigned int numElems = end - start + 1;
    r_type_ptr* a= calloc(numElems, sizeof(r_type_ptr));
    int i;

    for(i = 0; i < numElems; ++i){
        a[i] =thisRealiz->Entry->init(thisRealiz->Entry);
    }
    // create r_type_ptr to enable swapping entire arrays
    r_type_ptr** u = malloc(sizeof(r_type_ptr*));
    * u = a;
    return (r_type_ptr)u;
}

static void final_Static_Array_Instance(r_type_ptr toFree, type_info* ti)
{
    Static_Array_Template* thisRealiz = ti->PointerToFacility;
    int start = IF->ValueOf(thisRealiz->Lower_Bound);
    int end = IF->ValueOf(thisRealiz->Upper_Bound);

    unsigned int numElems = end - start + 1;
    r_type_ptr* array = *toFree;
    int i;
    for(i = 0; i < numElems; ++i){
        thisRealiz->Entry->final(array[i],thisRealiz->Entry);
    }
    // create r_type_ptr to enable swapping entire arrays
    free(*toFree);
    free(toFree);
}
static void Swap_Entry (r_type_ptr A, r_type_ptr E, r_type_ptr i, Static_Array_Template* thisRealiz)
{
    int index = IF->ValueOf(i)- IF->ValueOf(thisRealiz->Lower_Bound);
    rtype* array = *A;
    swap(E, array[index]);
}
static r_type_ptr Entry_Reference (r_type_ptr A, r_type_ptr i, Static_Array_Template* thisRealiz)
{
    int index = IF->ValueOf(i)- IF->ValueOf(thisRealiz->Lower_Bound);
    rtype* array = *A;
    return array[index];
}
extern Static_Array_Template* new_Std_Static_Array_Realization_for_Static_Array_Template(type_info* Entry, r_type_ptr Lower_Bound, r_type_ptr Upper_Bound)
{
    Static_Array_Template* sat = calloc(1, sizeof(Static_Array_Template));
    // store params
    sat->Upper_Bound = IF->Replica(Upper_Bound);
    sat->Lower_Bound = IF->Replica(Lower_Bound);
    sat->Entry = Entry;
    // init type_info
    sat->Static_Array = calloc(1, sizeof(type_info));
    sat->Static_Array->init = init_Static_Array_Instance;
    sat->Static_Array->final = final_Static_Array_Instance;
    sat->Static_Array->PointerToFacility = sat;
    // store function pointers
    sat->Swap_Entry = Swap_Entry;
    sat->Entry_Reference = Entry_Reference;

    return sat;
}
extern void free_Std_Static_Array_Realization_for_Static_Array_Template(Static_Array_Template* toFree)
{
    // Freeing stored parameters
    IF->IntTypeInfo->final(toFree->Upper_Bound, IF->IntTypeInfo);
    IF->IntTypeInfo->final(toFree->Lower_Bound, IF->IntTypeInfo);
    // Do not free Entry since it is not created here
    // Freeing data members
    free(toFree->Static_Array);
    // Freeing struct
    free(toFree);
}

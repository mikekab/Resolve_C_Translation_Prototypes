#include "Integers.h"
#include "Resolve.h"
#include "Stack_Template_co.h"
typedef struct Stack_Instance
{
    r_type_ptr* Contents;
    r_type_ptr Top;
}Stack_Instance;


extern type_info* newArrayRealizStackTypeInfo();
extern Stack_Template* new_Array_Realiz(type_info* TypeEntry, void* TypeEntryFacility, r_type_ptr MaxDepth);


#ifndef __STACK_TEMPLATE_CO_H
#define __STACK_TEMPLATE_CO_H

#include "Resolve.h"
typedef struct Stack_Template Stack_Template;
struct Stack_Template
{
     void (*Push)(r_type_ptr, r_type_ptr);
     void (*Pop)(r_type_ptr, r_type_ptr);
     void (*Clear)(r_type_ptr);
     r_type_ptr (*Depth)(r_type_ptr);
     // Parameters
     type_info* TypeEntry; // type info for Entry
     void* TypeEntryFacility; // Facility for Entry (in case the realization for entry is parameterized)
     r_type_ptr MaxDepth;
     // Types defined by this template
     type_info* Stack;
};
#endif

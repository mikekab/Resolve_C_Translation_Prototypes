#ifndef __ARRAY_REALIZ_RB_H
#define __ARRAY_REALIZ_RB_H

#include "Integers.h"
#include "Resolve.h"
#include "Stack_Template_co.h"
/*
Type Stack is represented by Record
            Contents: Array 1..Max_Depth of Entry;
            Top: Integer;
        end;
*/


extern Stack_Template* new_Array_Realiz_for_Stack_Template(type_info* TypeEntry, r_type_ptr MaxDepth);
extern void free_Array_Realiz_for_Stack_Template(Stack_Template* toFree);
#endif

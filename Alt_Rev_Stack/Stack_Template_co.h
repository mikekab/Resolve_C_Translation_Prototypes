#ifndef __STACK_TEMPLATE_CO_H
#define __STACK_TEMPLATE_CO_H

#include "Resolve.h"

/*
Concept Stack_Template(type Entry; evaluates Max_Depth: Integer);
    uses Modified_String_Theory;
    requires 1 <= Max_Depth;

    Type Family Stack is modeled by Str(Entry);
        exemplar S;
        constraint |S| <= Max_Depth;
        initialization ensures S = empty_string;

    Operation Push(alters E: Entry; updates S: Stack);
        requires |S| + 1 <= Max_Depth;
        ensures  S = <#E> o #S;

    Operation Pop(replaces R: Entry; updates S: Stack);
        requires |S| /= 0;
        ensures #S = <R> o S;

    Operation Depth(restores S: Stack): Integer;
        ensures Depth = (|S|);

    Operation Rem_Capacity(restores S: Stack): Integer;
        ensures Rem_Capacity = (Max_Depth - |S|);

    Operation Clear(clears S: Stack);

end Stack_Template;
*/
typedef struct Stack_Template Stack_Template;
struct Stack_Template
{
     // Operations.  Only Rem_Capacity needs the Stack_Template* parameter,
     void (*Push)(r_type_ptr, r_type_ptr, Stack_Template*);
     void (*Pop)(r_type_ptr, r_type_ptr, Stack_Template*);
     void (*Clear)(r_type_ptr, Stack_Template*);
     // The second parameter in these is the return value for the operation
     // This avoids dynamic allocation in the operation.
     void (*Depth)(r_type_ptr, r_type_ptr, Stack_Template*);
     void (*Rem_Capacity)(r_type_ptr, r_type_ptr, Stack_Template*);
     // Concept parameters
     type_info* TypeEntry; // type info for Entry
     r_type_ptr MaxDepth;
     // Types defined by this template
     type_info* Stack;
     // Place to attach realization only parameters
     void* OptionalParameters;
};
#endif

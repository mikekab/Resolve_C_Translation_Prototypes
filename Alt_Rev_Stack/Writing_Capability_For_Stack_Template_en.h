/*
Enhancement Writing_Capability for Stack_Template;
	Operation Write(clears S: Stack);
end Writing_Capability;
*/
#ifndef __Writing_Capability_for_Stack_Template
#define __Writing_Capability_for_Stack_Template

#include "Resolve.h"
#include "Stack_Template_co.h"

typedef struct Writing_Capability_for_Stack_Template Writing_Capability_for_Stack_Template;
struct Writing_Capability_for_Stack_Template
{
    void (*Write)(r_type_ptr, Writing_Capability_for_Stack_Template*);
    Stack_Template* Enhanced_Template;
    void* OptionalParams;
};

#endif

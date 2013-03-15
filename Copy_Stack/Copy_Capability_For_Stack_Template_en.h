#ifndef __Copy_Capability_for_Stack_Template
#define __Copy_Capability_for_Stack_Template
/*
Enhancement Copy_Capability for Stack_Template;

    Operation Copy_Stack(replaces S_Copy: Stack; restores S_Orig: Stack);
        ensures S_Copy = S_Orig;

end Copy_Capability;
*/
#include "Resolve.h"
#include "Stack_Template_co.h"

typedef struct Copy_Capability_for_Stack_Template Copy_Capability_for_Stack_Template;
struct Copy_Capability_for_Stack_Template
{
    void (*Copy_Stack)(r_type_ptr, r_type_ptr, Stack_Template*, Copy_Capability_for_Stack_Template*);
    void *OptionalParameters;
};
#endif

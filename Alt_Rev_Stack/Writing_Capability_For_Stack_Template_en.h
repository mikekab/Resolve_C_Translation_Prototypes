/*
Enhancement Writing_Capability for Stack_Template;
	Operation Write(clears S: Stack);
end Writing_Capability;
*/

#include "Resolve.h"
#include "Stack_Template_co.h"
typedef struct Writing_Capability_for_Stack_Template
{
    void (*Write)(r_type_ptr, Stack_Template*);
}Writing_Capability_for_Stack_Template;

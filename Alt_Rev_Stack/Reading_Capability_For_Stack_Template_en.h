/*
Enhancement Reading_Capability for Stack_Template;
	Operation Read_upto(replaces S: Stack; preserves Count: Integer);
		requires 0 <= Count and Count <= Max_Depth;

	Operation Read(replaces S: Stack);
end Reading_Capability;
*/
# ifndef __Reading_Capability_for_Stack_Template
# define __Reading_Capability_for_Stack_Template

#include "Resolve.h"
#include "Stack_Template_co.h"
typedef struct Reading_Capability_for_Stack_Template Reading_Capability_for_Stack_Template;
struct Reading_Capability_for_Stack_Template
{
    void (*Read_upto)(r_type_ptr S, r_type_ptr Count, Reading_Capability_for_Stack_Template* thisFac);
    void (*Read)(r_type_ptr, Reading_Capability_for_Stack_Template*);
    Stack_Template* Enhanced_Template;
    void* OptionalParameters;
};

# endif

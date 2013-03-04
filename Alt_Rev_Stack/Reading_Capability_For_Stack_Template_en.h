/*
Enhancement Reading_Capability for Stack_Template;
	Operation Read_upto(replaces S: Stack; preserves Count: Integer);
		requires 0 <= Count and Count <= Max_Depth;

	Operation Read(replaces S: Stack);
end Reading_Capability;
*/
#include "Resolve.h"
#include "Stack_Template_co.h"
typedef struct Reading_Capability_for_Stack_Template
{
    void (*Read_upto)(r_type_ptr, r_type_ptr);
    void (*Read)(r_type_ptr, Stack_Template*);
}Reading_Capability_for_Stack_Template;

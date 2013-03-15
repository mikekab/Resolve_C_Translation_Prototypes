#ifndef __Obvious_CC_Realiz_rb_h
#define __Obvious_CC_Realiz_rb_h

#include "Copy_Capability_For_Stack_Template_en.h"
/*
Realization Obvious_CC_Realiz
(
    operation Copy_Entry(replaces Copy: Entry; restores Orig: Entry);
        ensures Copy = Orig;

    )
for Copy_Capability of Stack_Template;
*/
Copy_Capability_for_Stack_Template* newObviousCCRealiz(void (*Copy_Entry)(r_type_ptr Entry, r_type_ptr Orig));
void freeObviousCCRealiz(Copy_Capability_for_Stack_Template* tofree);
#endif

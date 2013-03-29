/*
Concept Static_Array_Template(type Entry; evaluates Lower_Bound, Upper_Bound: Integer);
    uses Std_Integer_Fac;
    requires (Lower_Bound <= Upper_Bound);

    Type Family Static_Array is modeled by (Z -> Entry);
        exemplar A;
      constraint true;
        initialization ensures
		for all i: Z, Entry.Is_Initial(A(i));

    Operation Swap_Entry(updates A: Static_Array; updates E: Entry; evaluates i: Integer);
        requires Lower_Bound <= i  and i <= Upper_Bound;
	  ensures E = #A(i) and A = lambda j: Z.({{#E if j = i; #A(j) otherwise;}});

    Operation Swap_Two_Entries(updates A: Static_Array; evaluates i, j: Integer);
        requires Lower_Bound <= i  and i <= Upper_Bound and
                    Lower_Bound <= j  and j <= Upper_Bound;
        ensures A = lambda k: Z.({{#A(j) if k = i; #A(i) if k = j; #A(k) otherwise;}});

    Operation Assign_Entry(updates A: Static_Array; evaluates Exp: Entry; evaluates i: Integer);
        requires Lower_Bound <= i  and i <= Upper_Bound;
        ensures A = lambda j: Z.({{Exp if j = i; #A(j) otherwise;}});

    Operation Entry_Replica(restores A: Static_Array; evaluates i: Integer): Entry;
        requires Lower_Bound <= i  and i <= Upper_Bound;
        ensures Entry_Replica = A(i);
end Static_Array_Template;
*/
#ifndef __STATIC_ARRAY_TEMPLATE_H
#define __STATIC_ARRAY_TEMPLATE_H

#include "Resolve.h"

typedef struct Static_Array_Template Static_Array_Template;

struct Static_Array_Template{

     // Concept parameters
     type_info* Entry; // type info for Entry
     r_type_ptr Lower_Bound;
     r_type_ptr Upper_Bound;
     // Types defined by this template
     type_info* Static_Array;
     // Operations.
     void (*Swap_Entry)(r_type_ptr, r_type_ptr, r_type_ptr, Static_Array_Template*);
     void (*Swap_Two_Entries)(r_type_ptr, r_type_ptr, r_type_ptr, Static_Array_Template*);
     void (*Assign_Entry)(r_type_ptr, r_type_ptr, r_type_ptr, Static_Array_Template*);
     r_type_ptr (*Entry_Replica)(r_type_ptr, r_type_ptr, Static_Array_Template*);

     // Needed when array elements are passed as parameters
     r_type_ptr (*Entry_Reference)(r_type_ptr, r_type_ptr, Static_Array_Template*);
     // Place to attach realization only parameters and local objects
     void* Realization_Specific;
};
#endif

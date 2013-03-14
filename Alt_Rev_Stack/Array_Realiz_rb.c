#include "Array_Realiz_rb.h"
/*
Realization Array_Realiz for Stack_Template;

    Type Stack is represented by Record
            Contents: Array 1..Max_Depth of Entry;
            Top: Integer;
        end;
        convention
            0 <= S.Top <= Max_Depth;
        correspondence
            Conc.S = Reverse(Concatenation i: Integer
            where 1 <= i <= S.Top, <S.Contents(i)>);

    Procedure Push(alters E: Entry; updates S: Stack);
        S.Top := S.Top + 1;
        E :=: S.Contents[S.Top];
    end Push;

    Procedure Pop(replaces R: Entry; updates S: Stack);
        R :=: S.Contents[S.Top];
        S.Top := S.Top - 1;
    end Pop;

    Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top;
    end Depth;

    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth - S.Top;
    end Rem_Capacity;

    Procedure Clear(clears S: Stack);
        S.Top := 0;
    end Clear;

end Array_Realiz;
*/
// init for the Stack type realized by Array_Realiz
// this is attached to a typeinfo struct named Stack
static r_type_ptr init_Stack(type_info* stackType)
{
    Stack_Template* ar = stackType->PointerToFacility;
    int numElems = IF->ValueOf(ar->MaxDepth);
    Stack_Instance* si = calloc(1, sizeof(Stack_Instance));
    si->Contents = CreateArrayOf(1, numElems, ar->TypeEntry);
    si->Top = IF->IntTypeInfo->init(IF->IntTypeInfo);
    Stack_Instance** t = malloc(sizeof(Stack_Instance*));
    *t = si;
    return (r_type_ptr)t;
}

static void final_Stack(r_type_ptr r, type_info* ti)
{
    Stack_Instance* SI = *r;
    Stack_Template* ar = ti->PointerToFacility;
    FreeArrayOf(ar->MaxDepth, SI->Contents, ar->TypeEntry);
    IF->IntTypeInfo->final(SI->Top, IF->IntTypeInfo);
    free(*r);
    free(r);
}



// local helper function
static type_info* newArrayRealizStackTypeInfo()
{
    type_info* ti = calloc(1, sizeof(type_info));
    ti->init = init_Stack;
    ti->final = final_Stack;
    return ti;
}
/*
Procedure Push(alters E: Entry; updates S: Stack);
        S.Top := S.Top + 1;
        E :=: S.Contents[S.Top];
    end Push;
*/
static void Push(r_type_ptr E, r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    IF->Increment(SI->Top);
    swap(E,ArrayElementAt(SI->Top, SI->Contents));

}
/*
 Procedure Pop(replaces R: Entry; updates S: Stack);
        R :=: S.Contents[S.Top];
        S.Top := S.Top - 1;
    end Pop;
*/
static void Pop(r_type_ptr R, r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    swap(R,ArrayElementAt(SI->Top, SI->Contents));
    IF->Decrement(SI->Top);

}
/*
   Procedure Depth(preserves S: Stack): Integer;
        Depth := S.Top;
    end Depth;
*/
static r_type_ptr Depth(r_type_ptr S, r_type_ptr AssignTo, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    IF->Copy(SI->Top, AssignTo);
    return AssignTo;
}
/*
    Procedure Rem_Capacity(preserves S: Stack): Integer;
        Rem_Capacity := Max_Depth - S.Top;
    end Rem_Capacity;
*/
static r_type_ptr Rem_Capacity(r_type_ptr S, r_type_ptr AssignTo, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    IF->Subtract(AssignTo, thisFac->MaxDepth, SI->Top);
    return AssignTo;
}
/*
    Procedure Clear(clears S: Stack);
        S.Top := 0;
    end Clear;
*/
static void Clear(r_type_ptr S, Stack_Template* thisFac)
{
    Stack_Instance* SI = *S;
    IF->AssignLiteral(SI->Top, 0);
}

// Assigns values to the structure defined in the concept
extern Stack_Template* new_Array_Realiz(type_info* TypeEntry, r_type_ptr MaxDepth)
{
    Stack_Template* ar = calloc(1, sizeof(Stack_Template));
    ar -> Push = Push;
    ar -> Pop = Pop;
    ar -> Clear = Clear;
    ar -> Depth = Depth;
    ar -> Rem_Capacity = Rem_Capacity;
    ar -> TypeEntry = TypeEntry;
    ar -> MaxDepth = MaxDepth;
    ar -> Stack = newArrayRealizStackTypeInfo();
    ar -> Stack -> PointerToFacility = ar;
    return ar;
}



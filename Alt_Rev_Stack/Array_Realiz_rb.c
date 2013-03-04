#include "Array_Realiz_rb.h"
#include "Integers.h"

// init for the Stack type realized by Array_Realiz
static r_type_ptr init(void* vp)
{
    Stack_Template* ar = vp;
    Integer_Fac* IF = newIntegerFac();
    type_info* intType = newIntTypeInfo();
    int numElems = IF->ValueOf(ar->MaxDepth);
    Stack_Instance* si = calloc(1, sizeof(Stack_Instance));
    si->Contents = ar->TypeEntry->CreateArrayOf(numElems, ar->TypeEntryFacility);

    si->Top = intType->init(IF);
    IF->AssignLiteral(si->Top, 0);
    Stack_Instance** t = malloc(sizeof(Stack_Instance*));
    *t = si;
    return (r_type_ptr)t;
}

static void final(r_type_ptr r)
{
    Stack_Instance* t = *r;
    free(*(t->Contents));
    free(*(t->Top));
    free(*r);
}


static r_type_ptr* CreateArrayOf(unsigned int s, Stack_Template* ar)
{
    type_info* stackType = ar->Stack;
    r_type_ptr* a= calloc(s, sizeof(r_type_ptr));
    int i;
    for(i = 0; i < s; ++i){
        a[i] = stackType->init(ar);
    }
    return a;
}

extern type_info* newArrayRealizStackTypeInfo()
{
    type_info* ti = calloc(1, sizeof(type_info));
    ti->init = init;
    ti->final = final;
    ti->CreateArrayOf = CreateArrayOf;
    return ti;
}
static void Push(r_type_ptr E, r_type_ptr S)
{
    Integer_Fac* IF = newIntegerFac();

    Stack_Instance* SI = *S;
    r_type_ptr Top = SI->Top;
    int idx = IF->ValueOf(Top) -1;
    IF->Increment(Top);
    idx = IF->ValueOf(Top) -1;
    r_type_ptr ae = SI->Contents[idx];

    swap(E,ae);

}

static void Pop(r_type_ptr E, r_type_ptr S)
{
    Integer_Fac* IF = newIntegerFac();

    Stack_Instance* SI = *S;
    r_type_ptr Top = SI->Top;

    int idx = IF->ValueOf(Top) -1;
    r_type_ptr ae = SI->Contents[idx];
    IF->Decrement(Top);
    swap(E,ae);
}
static void Clear(r_type_ptr S)
{
    Integer_Fac* IF = newIntegerFac();
    Stack_Instance* SI = *S;
    IF->AssignLiteral(SI->Top, 0);
}
static r_type_ptr Depth(r_type_ptr S)
{
    Stack_Instance* SI = *S;
    return SI->Top;
}

extern Stack_Template* new_Array_Realiz(type_info* TypeEntry, void* TypeEntryFacility, r_type_ptr MaxDepth)
{
    Stack_Template* ar = calloc(1, sizeof(Stack_Template));
    ar -> Push = Push;
    ar -> Pop = Pop;
    ar -> Clear = Clear;
    ar -> Depth = Depth;
    ar -> TypeEntry = TypeEntry;
    ar -> TypeEntryFacility = TypeEntryFacility;
    ar -> MaxDepth = MaxDepth;
    ar -> Stack = newArrayRealizStackTypeInfo();
    return ar;
}



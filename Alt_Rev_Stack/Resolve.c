#include "Resolve.h"

void swap(r_type_ptr A, r_type_ptr B){
  void* temp = *A;

  *A = *B;
  *B = temp;
}


#include "status.h"

typedef void* VECTOR;

VECTOR vector_init_default(void);


//look at and change what it is holding at the ith element
int* vector_at(VECTOR hVector, int index);

Status vector_push_back(VECTOR hVector, int value);
Status vector_pop_back(VECTOR hVector);
Boolean vector_is_empty(VECTOR hVector);

int vector_get_capacity(VECTOR hVector);
int vector_get_size(VECTOR hVector);


void vector_destroy(VECTOR* phVector);
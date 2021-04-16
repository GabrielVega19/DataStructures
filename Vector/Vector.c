#include <stdio.h>
#include "Vector.h"

struct vector {
	int size; 
	int capacity;
	int* data;
};

typedef struct vector Vector;

VECTOR vector_init_default(void) {
	Vector* pVector = (Vector*)malloc(sizeof(Vector));
	if (pVector != NULL) {
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL) {
			free(pVector);
			return NULL;
		}
	}

	return (VECTOR)pVector;
}
void vector_destroy(VECTOR* phVector) {
	Vector* pVector = (Vector*)*phVector;
	free(pVector->data);
	free(pVector);
	
	
	*phVector = NULL;
}
int vector_get_capacity(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;
	return pVector->capacity;
}
int vector_get_size(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;
	return pVector->size;
}

Status vector_push_back(VECTOR hVector, int value) {
	Vector* pVector = (Vector*)hVector;
	int* temp;
	int i;

	//if there is not enough room make room
	// now we know that there must be enough room
	if (pVector->size >= pVector->capacity) {
		temp = (int*)malloc(sizeof(int) * pVector->capacity * 2);
		if (temp == NULL) {
			return Failure;
		}
		for (i = 0; i < pVector->size; i++) {
			temp[i] = pVector->data[i];
		}
		free(pVector->data);
		pVector->capacity *= 2;
		pVector->data = temp;
	}
	pVector->data[pVector->size] = value;
	pVector->size++;
	return Success;
}

Status vector_pop_back(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;

	if (pVector->size == 0) {
		return Failure;
	}

	pVector->size--;
	return Success;
}

Boolean vector_is_empty(VECTOR hVector) {
	Vector* pVector = (Vector*)hVector;

	return (Boolean)(pVector->size <= 0);
}

int* vector_at(VECTOR hVector, int index) {
	Vector* pVector = (Vector*)hVector;

	if (index >= 0 && index < pVector->size) {
		return &(pVector->data[index]);
		// other method same thing return pVector->data + index;
	}
	return NULL;
}
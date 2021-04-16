#include "stack.h"
#include "status.h"
#include <stdlib.h>
#include <stdio.h>

struct stack {
	int size;
	int capacity;
	int* data;
};
typedef struct stack Stack;


STACK stack_init_default(void) {
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL) {
		pStack->size = 0;
		pStack->capacity = 7;
		pStack->data = (int*)malloc(sizeof(int) * pStack->capacity);
		if (pStack->data == NULL) {
			free(pStack);
			return NULL;
		}
	}
	return pStack;
}

Status stack_push(STACK hStack, int value) {
	Stack* pStack = (Stack*)hStack;
	int* temp;
	int i;

	//if there is not room make room
	if (pStack->size >= pStack->capacity) {
		temp = (int*)malloc(sizeof(int) * pStack->capacity * 2);
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pStack->size; i++) {
			temp[i] = pStack->data[i];
		}
		free(pStack->data);
		pStack->data = temp;
		pStack->capacity *= 2;
	}
	
	pStack->data[pStack->size] = value;
	pStack->size++;
	return SUCCESS;
}
Status stack_pop(STACK hStack) {
	Stack* pStack = (Stack*)hStack;
	
	if (stack_empty(hStack)) {
		return FAILURE;
	}

	pStack->size--;
	return SUCCESS;
}
Boolean stack_empty(STACK hStack) {
	Stack* pStack = (Stack*)hStack;

	return (Boolean)(pStack->size <= 0);
}
int stack_top(STACK hStack, Status* pStatus){
	Stack* pStack = (Stack*)hStack;
	

	if (stack_empty(hStack)) {
		if (pStatus != NULL) {
			*pStatus = FAILURE;
		}
		return -12321;
	}

	if (!stack_empty(hStack)) {
		*pStatus = SUCCESS;
	}
	return pStack->data[pStack->size - 1];
}

void stack_destroy(STACK* phStack) {
	Stack* pStack = (Stack*)*phStack;
	free(pStack->data);
	free(pStack);
	*phStack = NULL;
}
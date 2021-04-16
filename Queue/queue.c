#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "status.h"

struct queue {
	int size;
	int capacity;
	int index_front;
	int* data;
};
typedef struct queue Queue;

QUEUE queue_init_default(void) {
	Queue* pQ = (Queue*)malloc(sizeof(Queue));
	if (pQ != NULL) {
		pQ->size = 0;
		pQ->capacity = 7;
		pQ->index_front = 0;
		pQ->data = (int*)malloc(sizeof(int) * pQ->capacity);
		if (pQ->data == NULL) {
			free(pQ);
			return NULL;
		}
	}
	return (QUEUE)pQ;
}

Status queue_enqueue(QUEUE hQ, int value) {
	Queue* pQ = (Queue*)hQ;

	if (pQ->size >= pQ->capacity) {
		int* temp = (int*)malloc(sizeof(int) * pQ->capacity * 2);
		if (temp == NULL) {
			return FAILURE;
		}
		for (int i = 0; i < pQ->size; i++) {
			temp[i] = pQ->data[(pQ->index_front + i) % pQ->capacity];
		}
		pQ->capacity *= 2;
		pQ->index_front = 0;
		free(pQ->data);
		pQ->data = temp;
	}
	pQ->data[(pQ->size + pQ->index_front) % pQ->capacity] = value;
	pQ->size++;
	return SUCCESS;
}
Status queue_service(QUEUE hQ) {
	Queue* pQ = (Queue*)hQ;

	if (queue_empty(hQ)) {
		return FAILURE;
	}
	
	pQ->index_front = (pQ->index_front + 1) % pQ->capacity;
	pQ->size--;

	return SUCCESS;
}
Boolean queue_empty(QUEUE hQ) {
	Queue* pQ = (Queue*)hQ;
	
	return (Boolean)(pQ->size <= 0);
}
int queue_front(QUEUE hQ, Status* pStatus) {
	Queue* pQ = (Queue*)hQ;
	
	if (queue_empty(hQ)) {
		
		if (pStatus != NULL) {
			*pStatus = FAILURE;
		}
		return -329429;
	}
	if (pStatus != NULL) {
		*pStatus = SUCCESS;
	}

	return pQ->data[pQ->index_front];
}

void queue_destroy(QUEUE* hpQ) {
	Queue* pQ = (Queue*)*hpQ;
	free(pQ->data);
	free(pQ);
	*hpQ = NULL;
}

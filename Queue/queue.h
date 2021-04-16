#ifndef QUEUE_H
#define QUEUE_H

#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQ, int value);
Status queue_service(QUEUE hQ);
Boolean queue_empty(QUEUE hQ);
int queue_front(QUEUE hQ, Status* pStatus);

void queue_destroy(QUEUE* hpQ);

#endif
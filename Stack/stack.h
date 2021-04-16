#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, int value);
Status stack_pop(STACK hStack);
Boolean stack_empty(STACK hStack);
int stack_top(STACK hStack, Status* pStatus);

void stack_destroy(STACK* phStack);
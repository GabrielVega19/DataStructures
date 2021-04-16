#include <stdio.h>
#include "stack.h"
#include "status.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
	STACK hStack;
	int i = 0;
	Status status;

	hStack = stack_init_default();
	if (hStack == NULL) {
		printf("failed to allocate space for hStack");
		exit(1);
	}

	for (i = 0; i < 10; i++) {
		if (!stack_push(hStack, i)) {
			printf("failed to push into stack");
		}
	}
	while (!stack_empty(hStack)) {
		printf("the top of the stack is %d\n", stack_top(hStack, &status));
		if (!stack_pop(hStack)) {
			printf("this should never happen");
			exit(1);
		}
	}


	stack_destroy(&hStack);

	return 0;
}
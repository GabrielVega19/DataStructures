#include <stdio.h>
#include "status.h"
#include "queue.h"

int main(int argc, char* argv[]) {
	QUEUE hQ;

	hQ = queue_init_default();
	if (hQ == NULL) {
		printf("Failed to allocate space for hQ");
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		if (!queue_enqueue(hQ, i)) {
			exit(1);
		}
	}

	while (!queue_empty(hQ)) {
		printf("the front is %d\n", queue_front(hQ, NULL));
		if (!queue_service(hQ)) {
			printf("shouldnt happen\n");
			exit(1);
		}
	}

	queue_destroy(&hQ);

	return 0;
}
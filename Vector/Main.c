#include "Vector.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	VECTOR hVector;

	hVector = vector_init_default();
	if (hVector == NULL) {
		printf("failed to allocate memory");
		exit(1);
	}

	printf("%d/%d\n", vector_get_size(hVector), vector_get_capacity(hVector));
	for (int i = 0; i < 10; i++) {
		if (!vector_push_back(hVector, i)) {
			printf("Failed to add");
		}
		printf("%d/%d\n", vector_get_size(hVector), vector_get_capacity(hVector));
	}

	for (int i = 0; i < 10; i++) {

	}
	*vector_at(hVector, 4) = -1;

	while (vector_pop_back(hVector)) {
		printf("pop\n");
	}

	vector_destroy(&hVector);

	return 0;
}
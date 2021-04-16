#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl_tree.h"

int main(int argc, char* argv[]) {
	srand(time(0));
	AVL_TREE root = NULL;

	for (int i = 0; i < 1000000; i++) {
		avl_tree_insert(&root, rand());
	}

	printf("\n\n\nThe height of the tree is: %d", avl_tree_height(root));

	avl_tree_destroy(&root);

	return 0;
}
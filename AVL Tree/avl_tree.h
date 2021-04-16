#ifndef AVL_TREE_H 
#define AVL_TREE_H

typedef void* AVL_TREE;

void avl_tree_insert(AVL_TREE* phRoot, int value);
void avl_tree_traversal(AVL_TREE hRoot);
void avl_tree_destroy(AVL_TREE* phRoot);
int avl_tree_height(AVL_TREE hRoot);



#endif
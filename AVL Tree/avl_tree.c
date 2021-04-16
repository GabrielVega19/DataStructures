#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct node;
typedef struct node Node;

struct node {
	int value;
	Node* left_child;
	Node* right_child;
	int height;
};

void node_insert(AVL_TREE* phRoot, int value) {
	Node* temp = (Node*)malloc(sizeof(Node));

	if (temp != NULL) {
		temp->value = value;
		temp->left_child = NULL;
		temp->right_child = NULL;
		temp->height = 1;
	}
	*phRoot = (AVL_TREE)temp;
}

int height(Node* node) {

	if (node == NULL) {
		return 0;
	}
	else {
		return node->height;
	}
}

int balance(Node* node) {
	
	return (height(node->right_child) - height(node->left_child));
}

void right_turn(Node** root) {
	Node* temp = (*root)->left_child;
	Node* temp0 = temp->right_child;

	temp->right_child = *root;
	(*root)->left_child = temp0;
	*root = temp;

	Node* right = (*root)->right_child;
	right->height = 1 + max(height(right->left_child), height(right->right_child));
	(*root)->height = 1 + max(height((*root)->left_child), height((*root)->right_child));
}

void left_turn(Node** root) {
	Node* temp = (*root)->right_child;
	Node* temp0 = temp->left_child;

	temp->left_child = *root;
	(*root)->right_child = temp0;
	*root = temp;

	Node* left = (*root)->left_child;
	left->height = 1 + max(height(left->left_child), height(left->right_child));
	(*root)->height = 1 + max(height((*root)->left_child), height((*root)->right_child));
}

void avl_tree_insert(AVL_TREE* phRoot, int value) {
	Node* pRoot = (Node*)*phRoot;
	
	if (pRoot == NULL) {
		node_insert(phRoot, value);
		return;
	}
	else if (value < pRoot->value) {
		avl_tree_insert(&(pRoot->left_child), value);
	}
	else if (value > pRoot->value) {
		avl_tree_insert(&(pRoot->right_child), value);
	}
	else {
		return;
	}

	pRoot->height = 1 + max(height(pRoot->left_child), height(pRoot->right_child));


	if (balance(pRoot) > 1 && balance(pRoot->right_child) > 0) {
		left_turn((Node**)phRoot);
	}
	else if (balance(pRoot) < -1 && balance(pRoot->left_child) < 0) {
		right_turn((Node**)phRoot);
	}
	else if (balance(pRoot) > 1 && balance(pRoot->right_child) < 0) {
		right_turn(&pRoot->right_child);
		left_turn((Node**)phRoot);
	}
	else if (balance(pRoot) < -1 && balance(pRoot->left_child) > 0) {
		left_turn(&pRoot->left_child);
		right_turn((Node**)phRoot);
	}


	return;
}

void avl_tree_destroy(AVL_TREE* phRoot) {
	Node* pRoot = (Node*)*phRoot;
	
	if (pRoot != NULL) {
		avl_tree_destroy(&pRoot->left_child);
		avl_tree_destroy(&pRoot->right_child);

		free(pRoot);
		*phRoot = NULL;
	}
	return;
}

void avl_tree_traversal(AVL_TREE hRoot) {
	Node* root = (Node*)hRoot;

	if (root != NULL) {
		avl_tree_traversal((AVL_TREE)root->left_child);
		printf("%d,%d / ", root->value, root->height);
		avl_tree_traversal((AVL_TREE)root->right_child);
	}


	return;
}

int avl_tree_height(AVL_TREE hRoot) {
	Node* pRoot = (Node*)hRoot;

	return pRoot->height;
}




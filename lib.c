#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


Node *create_node(int key) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Memory allocation error for the new node\n");
		exit(1);
	}
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	return new_node;
}


Node* insert_node(Node* root, int key) {
	if (root == NULL) {
		return create_node(key);
	}
	if (key < root->key) {
		root->left = insert_node(root->left, key);
	} else if (key > root->key) {
		root->right = insert_node(root->right, key);
	}
	return root;
}
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

Node* get_min(Node* root) {
	if (root == NULL) return NULL;
	if (root->left == NULL) return root;
	return get_min(root->left);
}

Node* get_max(Node* root) {
	if (root == NULL) return NULL;
	if (root->right == NULL) return root;
	return get_max(root->right);
}

int get_length(int num) {
    int length = 0;
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        length++;
        num = num / 10;
    }

    return length;
}

void print_tree(Node* root, int depth, int is_last_child) {
	if (root == NULL) return;
	for (int i = 0; i < depth - 1; i++) {
		printf("%s", NODE_PREFIX_TOP_LEVEL);
	}

	if (depth) {
		if (is_last_child) {
			printf("%s", NODE_PREFIX_LAST);
		} else {
			printf("%s", NODE_PREFIX);
		}
	}

	printf("(%d)\n", root->key);
	print_tree(root->right, depth + 1, 0);
	print_tree(root->left, depth + 1, 1);

}

#ifndef LAB_WORKS_LIB_H
#define LAB_WORKS_LIB_H

typedef struct node
{
	int key;
	float value;
	struct node *left;
	struct node *right;
	struct node *parent;
} Node;


Node *create_node(int key);
Node* insert_node(Node* root, int key);
Node* get_min(Node* root);

#endif
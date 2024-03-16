#include <string.h>
#include <stdio.h>
#include "lib.h"

void help_command() {
	printf("ins <value>: add a new node to the tree\n");
	printf("del <value>: remove a node from the tree\n");
	printf("show: show tree structure in terminal\n");
	printf("clear: clear the tree structure\n\n");
}

void invalid_command(char* command) {
	printf("%s: command not found\n", command);
	printf("Type 'help' to learn about commands\n\n");
}


void ins_command(Node** root) {
	int key;
	scanf("%d", &key);
	*root = insert_node(*root, key);
	printf("OK\n\n");
}


void get_max_command(Node * root) {
	Node* max_node = get_max(root);
	if (max_node == NULL) {
		printf("the tree is empty");
	} else {
		printf("%d - the largest node of the tree\n\n", max_node->key);
	}
}

void get_min_command(Node * root) {
	Node* min_node = get_min(root);
	if (min_node == NULL) {
		printf("the tree is empty");
	} else {
		printf("%d - the smallest node of the tree\n\n", min_node->key);
	}
}

int main(void) {
	Node* root = NULL;
	char command[20];
	printf("Type 'help' to learn about commands\n\n");
	while (1) {
		printf("> ");
		scanf("%s", command);
		if (!strcmp(command, "help")) {
			help_command();
		} 
		else if (!strcmp(command, "ins")) {
			ins_command(&root);
		} 
		else if (!strcmp(command, "get_min")) {
			get_min_command(root);
		} 
		else if (!strcmp(command, "get_max")) {
			get_max_command(root);
		} 
		else if (!strcmp(command, "get_root")) {
			printf("%d\n", root->key);
		} 
		else if (!strcmp(command, "del")) {

		} 
		else if (!strcmp(command, "show")) {

		} 
		else if (!strcmp(command, "clear")) {

		} 
		else {
			invalid_command(command);
		}
	}

	return 0;
}
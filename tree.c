#include <string.h>
#include <stdio.h>
#include "lib.h"


void help_command() {
	printf("\tins <value>  : add a new node to the tree\n");
	printf("\tdel <value>  : remove a node from the tree\n");
	printf("\tshow         : show tree structure in terminal\n");
	printf("\tget_min      : show the smallest node of the tree\n");
	printf("\tget_max      : show the largest node of the tree\n");
	printf("\tget_root     : show the root node of the tree\n");
	printf("\tclear        : clear the tree structure\n");
	printf("\tis_width_increasing (iwi): check if the tree is width increasing\n");
	printf("\texit         : close the program");
}


void invalid_command(char* command) {
	printf("%s: command not found\n", command);
	printf("Type 'help' to learn about commands\n\n");
}


void ins_command(Node** root) {
	int key;
	scanf("%d", &key);
	*root = insert_node(*root, key);
	printf("%d was successfully inserted to the tree\n", key);
}


void get_max_command(Node * root) {
	Node* max_node = get_max(root);
	if (max_node == NULL) {
		printf("the tree is empty\n");
	} else {
		printf("\n");
		printf("%d - the largest node of the tree\n\n", max_node->key);
	}
}


void get_min_command(Node * root) {
	Node* min_node = get_min(root);
	if (min_node == NULL) {
		printf("the tree is empty\n");
	} else {
		printf("\n");
		printf("%d - the smallest node of the tree\n\n", min_node->key);
	}
}


void del_command(Node** root) {
	int key;
	scanf("%d", &key);
	*root = delete_node(*root, key);
	printf("%d was successfully deleted from the tree\n", key);
}


void show_command(Node* root) {
	if (root == NULL) {
		printf("The tree is empty\n");
	} else {
		printf("\n");
		print_tree(root, 0, 0);
		printf("\n");
	}
}


void clear_command(Node** root) {
	if (*root == NULL) {
		printf("The tree is empty\n");
	} else {
		printf("Tree clear visualization: \n\n");
		clear_tree(*root);
		*root = NULL;
		printf("The tree is empty now\n");
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
			del_command(&root);
		} 
		else if (!strcmp(command, "show")) {
			show_command(root);
		} 
		else if (!strcmp(command, "clear")) {
			clear_command(&root);
		} else if (!strcmp(command, "iwi") || !strcmp(command, "is_width_increasing")) {
			if (is_width_increasing(root)) {
				printf("True: The tree width is monotonously increasing\n");
			} else {
				printf("False: The tree width is not monotonously increasing\n");
			}

		} else if (!strcmp(command, "exit")) {
			clear_command(&root);
			exit(0);
		}
		else {
			invalid_command(command);
		}
	}
	return 0;
}
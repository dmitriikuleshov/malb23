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


int main(void) {
	Node* root = NULL;
	char command[20];
	printf("Type 'help' to learn about commands\n\n");
	while (1) {
		printf("> ");
		scanf("%s", command);
		if (!strcmp(command, "help")) {
			help_command();
		} else if (!strcmp(command, "ins")) {
			
		} else if (!strcmp(command, "del")) {

		} else if (!strcmp(command, "show")) {

		} else if (!strcmp(command, "clear")) {

		} else {
			invalid_command(command);
		}
	}

	return 0;
}
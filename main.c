/*
* file: token.c
* author: bhakti
* date: 15/03/2023
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "token.h"
#include "command.h"

int main() {
	char input[100];
	char *tokens[100];
	Command commands[100];
	do {
		printf("%% ");
		
		fgets(input, 100, stdin);
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
		printf("%s\n", input);
			
		int num = tokenise(input, tokens);
		for (int i = 0; i < num; i++) {
			printf("%s ", tokens[i]);
		}
		printf("\n");
		
		int numOfCommands = separateCommands(tokens, commands);
		
		printf("Number of commands = %d\n", numOfCommands);
		
//		for (int i = 0; i < numOfCommands; i++) {
//			for (int j = commands[i].first; j <= commands[i].last; j++) {
//				printf("%s ", tokens[j]);
//				printf("\n");
//			}
//			printf("\n");
//		}
		
		for (int i = 0; i < numOfCommands; i++) {
			printf("%s\n", commands[i].argv[0]);
			execvp(commands[i].argv[0], commands[i].argv);
		}
		
	} while (strcmp(input, "exit") != 0);
	
	return 1;
}

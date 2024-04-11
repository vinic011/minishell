#include "parse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char** parser(char* string, int * hasIn, char * input, int * hasOut, char * output) {

	char **tokens = malloc(MAX_TOKENS * sizeof(char*));
	char *token = strtok(string, DELIMITER);
	int count = 0;
	
	for (int i = 0; i < MAX_TOKENS; i++) {
		tokens[i] = malloc(MAX_TOKEN_LEN * sizeof(char));
	}
	
	while(token != NULL && count < MAX_TOKENS - 1) {
		if (strcmp(token,"<") == 0) {
			token = strtok(NULL, DELIMITER);
			*hasIn= 1;
			strcpy(input, token);
		} else if (strcmp(token,">") == 0) {
			token = strtok(NULL, DELIMITER);
			*hasOut = 1;
			strcpy(output, token);
		} else {
			
			strcpy(tokens[count], token);
			count ++;
		}
		
		token = strtok(NULL, DELIMITER);
	}
	
	tokens[count] = NULL;
	count ++;
	/*
	for (int i = 0; i < count; i++) {
		printf("\n%s\n",tokens[i]);
	}
	*/

	return tokens;
}

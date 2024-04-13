#include <stdio.h>

#include "src/parse/parse.h"
#include "src/execute/execute.h"


int main () {
	while (1) {
		printf("cmd>");
		
		char string[MAX_TOKENS * MAX_TOKEN_LEN];
		gets(string);
		int * nCommands = malloc(sizeof(int));
		char** commands = parseString(string, nCommands);

		for (int i = 0; i < *nCommands; i++) {
			int * hasIn = malloc(sizeof(int));
			char * input = malloc(MAX_TOKEN_LEN * sizeof(char));
		
			int * hasOut = malloc(sizeof(int));
			char * output = malloc(MAX_TOKEN_LEN * sizeof(char));

			char** argv = parseCommand(commands[i], hasIn, input, hasOut, output);
			execute(argv, hasIn, input, hasOut, output);
		}
	}
	return 0;
}

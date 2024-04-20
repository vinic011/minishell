#include <stdio.h>
#include <unistd.h>

#include "src/parse/parse.h"
#include "src/execute/execute.h"


int main () {
	while (1) {
		char string[MAX_TOKENS * MAX_TOKEN_LEN];
		printf("cmd>");
		
		gets(string);
		
		int * nCommands = malloc(sizeof(int));
		char** commands = parseString(string, nCommands);

		int nPipes = *nCommands - 1;
		int** pipes = malloc(nPipes*sizeof(int *));
		for (int i = 0; i < nPipes; i++) {
			pipes[i] = malloc(2*sizeof(int));
		}
		for (int i = 0; i < *nCommands; i++) {
			int * hasIn = malloc(sizeof(int));
			char * input = malloc(MAX_TOKEN_LEN * sizeof(char));
		
			int * hasOut = malloc(sizeof(int));
			char * output = malloc(MAX_TOKEN_LEN * sizeof(char));

			char** argv = parseCommand(commands[i], hasIn, input, hasOut, output);
			execute(argv, hasIn, input, hasOut, output, pipes, i, nPipes);
		}
		
	}

		

		
	
	return 0;
}

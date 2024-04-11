#include <stdio.h>

#include "src/parse/parse.h"
#include "src/execute/execute.h"


int main () {
	while (1) {
		printf("cmd>");
		
		char string[MAX_TOKENS * MAX_TOKEN_LEN];
		gets(string);
		
		int * hasIn = malloc(sizeof(int));
		*hasIn = 0;
		char * input = malloc(MAX_TOKEN_LEN * sizeof(char));
		
		int * hasOut = malloc(sizeof(int));
		*hasOut = 0;
		char * output = malloc(MAX_TOKEN_LEN * sizeof(char));
		
		char** argv = parser(string, hasIn, input, hasOut, output);
		
		
		execute(argv, hasIn, input, hasOut, output);
		

	}
	return 0;
}

#ifndef PARSE_H_
#define PARSE_H_

#define MAX_TOKENS 10
#define MAX_TOKEN_LEN 20
#define MAX_COM 10
#define DELIMITER " "
#define PIPE "|"

char** parseCommand(char * string, int * hasIn, char * input, int * hasOut, char * output);
char** parseString(char * string, int * nCommands);
#endif


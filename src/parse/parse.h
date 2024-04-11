#ifndef PARSE_H_
#define PARSE_H_

#define MAX_TOKENS 10
#define MAX_TOKEN_LEN 20
#define DELIMITER " "

char** parser(char * string, int * hasIn, char * input, int * hasOut, char * output);

#endif


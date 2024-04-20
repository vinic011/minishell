#ifndef EXECUTE_H_
#define EXECUTE_H_

void execute(char *argv[], 
                int * hasIn, char * input,
                int * hasOut, char * output,
                 int *pipes[], int i, int nPipes); 

void closePipes(int *pipes[], int numPipes);

#endif


#include "execute.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void execute(char *argv[], 
				int * hasIn, char * input, 
				int * hasOut, char * output,
				int *pipes[], int i, int nPipes) {

	char *pathname = argv[0];
	char *envp[] = {NULL};
		
	if ((i < nPipes) && (nPipes > 0)) {
		//printf("n pipes %d, current i %d\n", nPipes, i);
		pipe(pipes[i]);
	}

	if (!fork()) {
		if ((i < nPipes) && (nPipes > 0)) {
			close(pipes[i][0]);
		}
		if ((i > 0) && (nPipes > 0)) {
			close(pipes[i - 1][1]);
		}
		if ((i > 0) && (nPipes > 0)) {
			dup2(pipes[i - 1][0], 0);
		}
		if ((i < nPipes) && (nPipes > 0)) {
			dup2(pipes[i][1], 1);
		}

		int fd2,fd3;
		if (*hasIn == 1) {
			int fd = open(input, O_RDONLY);
			int fd2 = dup2(fd, 0);
		}
		
		if (*hasOut == 1) {
			int fd = open(output, O_WRONLY| O_CREAT | O_TRUNC, 0644);
			int fd3 = dup2(fd, 1);
		}
	
		execve(pathname, argv, envp);
		
		if (*hasIn == 1) {close(fd2);}
		if (*hasOut == 1) {close(fd3);}
			
	} 

	if ((i > 0) && (nPipes > 0)) {
		close(pipes[i - 1][0]);	
		close(pipes[i - 1][1]);	
	}
}

void closePipes(int *pipes[], int numPipes) {
	for (int i = 0; i < numPipes; i++) {
		for (int j = 0; j < 2; j++) {
			close(pipes[i][j]);
		}
	}
}
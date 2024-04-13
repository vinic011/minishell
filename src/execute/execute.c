#include "execute.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void execute(char *argv[], int * hasIn, char * input, int * hasOut, char * output) {
	char *pathname = argv[0];
	char *envp[] = {NULL};
		
	if (!fork()) {
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
			
	} else {
		wait(NULL);
	}
}

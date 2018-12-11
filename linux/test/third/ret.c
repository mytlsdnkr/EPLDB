/*
Q. Complete a program which implements the system() system call 
   using fork() and related system calls.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

//#############################################################################
int system_using_fork(char *cmd)
{
	// start of your code .........................

	pid_t pid;


	// start of your code .........................

}


#define STR_CMD "ls -l -a"
//#############################################################################
int main(int argc, char **argv)
{

	system(STR_CMD);

	system_using_fork(STR_CMD);

	exit(EXIT_SUCCESS);
}


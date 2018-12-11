#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

/*
Q. Complete a program which implements the following shell command 
	using unnamed pipe system call.
	] ls –l /etc/ | head | wc
*/


//#############################################################################
void system_using_unnamed_pipe()
{

    int fd;
    int file_pipes1[2], file_pipes2[2];
    pid_t fork_result;

    if (pipe(file_pipes1) != 0)
	{
		fprintf(stderr, "pipe failure");
		exit(EXIT_FAILURE);
	}

    if (pipe(file_pipes2) != 0)
	{
		fprintf(stderr, "pipe failure");
		exit(EXIT_FAILURE);
	}
			
	// start of your code .........................



	// end of your code ...........................
}



//#############################################################################
int main(int argc, char **argv)
{

	system("ls -l /etc | head | wc");

	printf("-----------------------------------\n");

	// implement "ls -l /etc | head | wc" using pipe()
	system_using_unnamed_pipe();

	exit(EXIT_SUCCESS);
}


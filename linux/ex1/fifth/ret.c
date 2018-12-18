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
    int file_pipes1[2];
    pid_t fork_result;
        

    if (pipe(file_pipes1) != 0)
	{
		fprintf(stderr, "pipe failure");
		exit(EXIT_FAILURE);
	}

    fd=open("b.txt",O_WRONLY|O_CREAT,0777);
        fork_result=fork();
        if(fork_result==0){
            dup2(file_pipes1[1],1);
            close(file_pipes1[1]);
            execlp("cat","cat","ret.c",(char *)0);
        
        }

        
        dup2(file_pipes1[0],0);
        close(file_pipes1[0]);
        dup2(fd,1);
        close(file_pipes1[1]);
        execlp("wc","wc",(char *)0);

        close(fd);

        




}



//#############################################################################
int main(int argc, char **argv)
{

//	system("cat < ret.c | wc > a.txt ");

//	printf("-----------------------------------\n");

	// implement "ls -l /etc | head | wc" using pipe()
	system_using_unnamed_pipe();

	exit(EXIT_SUCCESS);
}


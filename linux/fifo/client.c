#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//#############################################################################
// Request: Complete the following functions. 
// Due    : Dec. 11, 2017 18:00
//#############################################################################


//#############################################################################
// Complete the client program which acts as follows
// - read a string from the 1st argument of the program. ex) ./client abc
// - print the string on the screen
// - send the string to the server through a named pipe [./fifo_StdNo]
// - receive a string from the server through the named pipe [./fifo_StdNo]
// - print the received string on the screen.


/* example

step 1. [client] ---> "abc" ---> [server]
step 2. [client] <--- "ABC" <--- [server]

*/

#define FIFO_NAME "./fifo_StdNo"
#define BUFFER_SIZE 100
//#############################################################################
int main(int argc, char **argv)
{

    int pipe_fd;
    int res=0, i;
    int open_mode = O_WRONLY;
    int open_mode1= O_RDONLY;
    char buffer[BUFFER_SIZE];

	if (argc != 2)
	{
		printf("USAGE: ] ./client [string] \n");
		exit(0);
	}

	strcpy( buffer, argv[1]);
    printf("Client Input  Data: %s\n", buffer); //exit(0);

    if(access(FIFO_NAME,F_OK)==-1){
        res=mkfifo(FIFO_NAME,0777);
        if(res != 0){
            fprintf(stderr,"Could not create fifo %s\n",FIFO_NAME);
            exit(EXIT_FAILURE);
        }
    }

    pipe_fd=open(FIFO_NAME,open_mode);

    if(pipe_fd != -1){
        res=write(pipe_fd,buffer,strlen(buffer));
        if(res==-1){
            fprintf(stderr,"Write error on pipe\n");
            exit(EXIT_FAILURE);      
       }
        (void)close(pipe_fd);
        sleep(1);
        pipe_fd=open(FIFO_NAME,open_mode1);
        if(pipe_fd!=-1){
            res=read(pipe_fd,buffer,strlen(buffer));
            close(pipe_fd);
        }else{
            exit(EXIT_FAILURE);
        }

    }else{
        exit(EXIT_FAILURE);
    }

	printf("Client Output Data: %s\n", buffer);

	sleep(1);
	printf("\n\n");
    printf("Client Process %d finished\n", getpid());
	printf("Client Execution finished successfully.... \n");
    exit(EXIT_SUCCESS);

}


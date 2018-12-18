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
// Complete the server/client program which acts as follows
// - receive a string from a client through a named pipe [./fifo_StdNo] 
// - print the string  on the screen
// - convert the string to UPPER case.
// - print the result string on the screen.
// - send the result string to the client through a named pipe [./fifo_StdNo]


/*

step 1. [client] ---> "abc" ---> [server]
step 2. [client] <--- "ABC" <--- [server]

*/


#define FIFO_NAME "./fifo_StdNo"
#define BUFFER_SIZE 100

//#############################################################################
int main(int argc, char **argv)
{
	int i;
    int pipe_fd;
    int open_mode=O_RDONLY;
    int open_mode1=O_WRONLY;
    int res=0;
    char buffer[BUFFER_SIZE];
	if (argc != 1)
	{
		printf("USAGE: ] ./server \n");
		exit(0);
	}

    memset(buffer, '\0', sizeof(buffer));
    
    pipe_fd=open(FIFO_NAME,open_mode);
    if(pipe_fd != -1){
        res=read(pipe_fd,buffer,BUFFER_SIZE);
        printf("I got a meessage : %s\n",buffer);
        sleep(1);
        for(i=0;i<strlen(buffer);i++){
            buffer[i]-=32;
        }
        close(pipe_fd);
        pipe_fd=open(FIFO_NAME,open_mode1);
        if(pipe_fd != -1){
            res=write(pipe_fd,buffer,strlen(buffer));
            printf("Server Process send %s \n",buffer);
        }else{
            exit(EXIT_FAILURE);
        }
    }else{
        exit(EXIT_FAILURE);
    }
	sleep(1);
	printf("\n\n");
	printf("Server Process %d finished\n", getpid());
  	printf("Server Execution finished successfully.... \n");
    exit(EXIT_SUCCESS);

}


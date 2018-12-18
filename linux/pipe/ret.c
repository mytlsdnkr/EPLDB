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
// Due    : Dec. 10, 2018 16:00
//#############################################################################


// Implement the following shell command using pipe() functions
// ] ls -l | wc -lmc 




//#############################################################################
int main(int argc, char **argv)
{

   	int res, i;
	if (argc != 1)
	{
		printf("USAGE: ] ./ret \n");
		exit(EXIT_FAILURE);
	}

    int file_pipes[2];
    pid_t pid;
    


    if(pipe(file_pipes)==0){
        pid=fork();
        if(pid==0){
            close(1);
            dup(file_pipes[1]);
            close(file_pipes[1]);
            execlp("ls","ls","-l",(char *)0);
        }else{
            close(0);
            dup(file_pipes[0]);
            close(file_pipes[0]);
            close(file_pipes[1]);
            execlp("wc","wc",(char *)0);
        }
    }
	printf("Execution finished successfully.... \n\n");
    exit(EXIT_SUCCESS);

}


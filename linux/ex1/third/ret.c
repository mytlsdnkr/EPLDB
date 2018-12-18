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
#include <sys/wait.h>

//#############################################################################
int system_using_fork(char *cmd)
{
	// start of your code .........................

pid_t pid;
    int stat_val;
    char *firstarg;
    char *secondarg;
    char *thirdarg;
    
    char back[9];

    int i=0;
    for(i=0;i<9;i++){
        back[i]=cmd[i];
    }

    firstarg=strtok(back," ");
    
    secondarg=strtok(NULL," ");

    thirdarg=strtok(NULL," ");

        
         
      
        

    pid=fork();
    if(pid>0){
        wait(&stat_val);
    }

    if(pid==0){
        
        execl(firstarg,secondarg,thirdarg,(char *)0);

    }
    return 0;
  


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


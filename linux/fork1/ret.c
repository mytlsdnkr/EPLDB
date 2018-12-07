#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



//#############################################################################
// Request: Complete the following functions. 
// Due    : Nov. 19, 2018 16:00
//#############################################################################



//#############################################################################
// Complete this code which 
// 1. executes multiple "mysleep" programs simultaneously and
// 2. print out the following on the screen.
 
//	mysleep:   10000000
//	mysleep:    1000000
//	mysleep:     100000
//	mysleep:      10000
//	mysleep:       1000
//	mysleep:       1000
//	mysleep:      10000
//	mysleep:     100000
//	mysleep:    1000000
//	mysleep:   10000000
//	mysleep:    1000000
//	mysleep:     100000
//	mysleep:      10000
//	mysleep:       1000
//	mysleep:       1000
//	mysleep:      10000
//	mysleep:     100000
//	mysleep:    1000000

// You should use fork(), exec(), and wait()/waitpid() system calls to create child processes.
// 
//
int main(int argc, char **argv)
{
	int i,j,k,s;
    int stat_val;
	if (argc != 1)
	{
		printf("USAGE  : ] ./ret \n");
		exit(0);
	}

	// codes for multilple child process for multiple and concurrent execution 
	// of mysleep program
	// write your codes only here. 
	//----------------->
    
    int sleep_time=10000000;
    char sleep_str[100];

    sprintf(sleep_str,"%d",sleep_time);
    pid_t pid;
    pid_t ppid;
    for(i=0;i<5;i++){
        usleep(1000);
        pid=fork();
        if(pid==0){
            sprintf(sleep_str,"%d",sleep_time);
	        execl("./mysleep", "mysleep", sleep_str, 0);
        }else{
            sleep_time/=10;
        }
}
    for(i=0;i<5;i++){
        wait(&stat_val);
    }
    sleep_time=1000000;
    
    for(j=0;j<4;j++){

        usleep(1000);
        pid=fork();
        if(pid==0){
            sprintf(sleep_str,"%d",sleep_time);
	        execl("./mysleep", "mysleep", sleep_str, 0);
        }else{
            sleep_time/=10;
        }

    }

    for(j=0;j<4;j++){
        wait(&stat_val);
    }
	//<----------------

	printf("All child processes finished successfully.... \n\n");

	return 1;
}


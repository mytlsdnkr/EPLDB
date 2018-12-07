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




//#############################################################################
// Request: Complete the following functions. 
// Due    : Nov. 26, 2018 18:00
//#############################################################################



// 1. create 5 threads 
// 2. set a unique value(unsigned integer from 1 to 5) to each thread 
// 3. each thread prints out its value on the screen three times
// 4. the output on the screen should be as follows.

/*
	thread 0
	thread 1
	thread 2
	thread 3
	thread 4
	thread 0
	thread 1
	thread 2
	thread 3
	thread 4
	thread 0
	thread 1
	thread 2
	thread 3
	thread 4
	Execution finished successfully.... 
*/

#define MAX_THREAD	5

void *t_function(void *arg){
    int i=0;
    for(i=0;i<3;i++){
      printf("thread %d\n",(int *)arg);
      usleep(1000000);

    }
}



//#############################################################################
int main(int argc, char **argv)
{

    int res, i;
    void *thread_result;
    pthread_t a_thread[MAX_THREAD];
	int arg[MAX_THREAD];

	if (argc != 1)
	{
		printf("USAGE: ] ./ret \n");
		exit(0);
	}

    for(i=0;i<MAX_THREAD;i++){
        arg[i]=i;
        res=pthread_create(&a_thread[i],NULL,t_function,(void *)arg[i]);
        usleep(100000);
    }

    for(i=0;i<MAX_THREAD;i++){
        res=pthread_join(a_thread[i],&thread_result);
    }



	
	printf("Execution finished successfully.... \n\n");

}


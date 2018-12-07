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



//#############################################################################
// Request: Complete the following functions. 
// Due    : Nov. 27, 2018 18:00
//#############################################################################



// Make the function  print_int_list() to be executed one at a time by mutiple threads.
// Multiple execution of this function should not be interleaved.
// An example output should be like below:
//
//thread  3 = [  0  1  2  3]
//thread  1 = [  0  1  2  3  4  5  6]
//thread  2 = [  0  1  2  3  4  5  6  7  8  9]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  0 = [  0  1  2  3  4  5]
//thread  3 = [  0  1  2  3]
//thread  1 = [  0  1  2  3  4  5  6]
//thread  2 = [  0  1  2  3  4  5  6  7  8  9]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  0 = [  0  1  2  3  4  5]
//thread  3 = [  0  1  2  3]
//thread  1 = [  0  1  2  3  4  5  6]
//thread  2 = [  0  1  2  3  4  5  6  7  8  9]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  0 = [  0  1  2  3  4  5]


// write your codes here only
//----------------->
		
// ...

//----------------->

sem_t sem;

//#############################################################################
void print_int_list(int id, int max_num) 
{
	printf("thread %2d = [", id); fflush(stdout);
	
	for(int i=0; i<=max_num; i++)
	{
		printf("%3d", i); fflush(stdout);
		usleep(100000);
	}
	printf("]\n");
}



#define MAX_LOOP	3
//#############################################################################
void *thread_function(void *arg) 
{

	int id = *(int*)arg;

	int max_num = rand() % 10 + 1;	


	for(int i=0; i<MAX_LOOP; i++)
	{
		usleep(10000);
        sem_wait(&sem);
		print_int_list(id, max_num);
        sem_post(&sem);
	}

    pthread_exit(NULL);

	//----------------->


}



#define MAX_THREAD 5

//#############################################################################
int main(int argc, char **argv)
{

	if (argc != 1)
	{
		printf("USAGE: ] ./ret\n");
		exit(0);
	}

	srand( time(NULL) );



	// write your codes here only
	//---------------------------------------------------------------------------------->
			
	// ...

	int res, i;
    pthread_t thread_id[MAX_THREAD];
	int thread_arg[MAX_THREAD];

    res=sem_init(&sem,0,1);




	for( i=0; i<MAX_THREAD; i++)
	{
		thread_arg[i] = i;
		//printf("arg = %2d\n", thread_arg[i]);
		res = pthread_create(&thread_id[i], NULL, thread_function, (void *)&thread_arg[i]);
	}


	for( i=0; i<MAX_THREAD; i++)
	{
		res = pthread_join(thread_id[i], NULL);
		//printf("Thread %d finished ...\n", i);
	}

	// -----------------------------------------------------------------------------


	printf("Execution finished successfully.... \n\n");

}


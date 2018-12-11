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
// Q: Complete the following functions. 
//#############################################################################



// Make the function  print_int_list() to be executed one at a time by multiple threads.
// Multiple execution of this function should not be interleaved.
// All the threads execute the function one by one. 
// The sleep() or usleep() functions are not allowed.
// An example output should be like below:
//
//thread  0 = [  0  1]
//thread  1 = [  0  1]
//thread  2 = [  0  1  2  3  4  5]
//thread  3 = [  0  1  2  3  4  5  6]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  3 = [  0  1  2  3  4  5  6]
//thread  2 = [  0  1  2  3  4  5]
//thread  1 = [  0  1]
//thread  0 = [  0  1]
//thread  0 = [  0  1]
//thread  1 = [  0  1]
//thread  2 = [  0  1  2  3  4  5]
//thread  3 = [  0  1  2  3  4  5  6]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  4 = [  0  1  2  3  4  5  6  7]
//thread  3 = [  0  1  2  3  4  5  6]
//thread  2 = [  0  1  2  3  4  5]
//thread  1 = [  0  1]
//thread  0 = [  0  1]
//thread  0 = [  0  1]
//thread  1 = [  0  1]
//thread  2 = [  0  1  2  3  4  5]
//thread  3 = [  0  1  2  3  4  5  6]
//thread  4 = [  0  1  2  3  4  5  6  7]
//Execution finished successfully.... 



#define MAX_THREAD 5

sem_t g_sem_list[MAX_THREAD];
int g_flag  = 0;
int g_index = 0;

// write your codes here only if you need
//----------------->
		
// ...

//----------------->

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



#define MAX_LOOP	5
//#############################################################################
void *thread_function(void *arg) 
{
	// write your codes here only
	//----------------->
			
	// ...

	int id = *(int*)arg;

	int max_num  = rand() % 10 + 1;	

	for(int i=0; i<MAX_LOOP; i++)
	{
		print_int_list(id, max_num);


	}

    pthread_exit(NULL);

	//----------------->


}





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


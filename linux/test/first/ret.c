#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
/*

Q: Complete the get_the_n_th_sunday_of_the_year() 
	which return the date of the n-th Sunday of a given year.

*/

#define RET_SAME	0
#define RET_DIFF	1

//#############################################################################
// complete this function
int get_the_n_th_sunday_of_the_year(int year, int n_th)
{
	struct tm tm_a;
	time_t tv_a;
	int day;
	
	memset(&tm_a, 0, sizeof(struct tm));

	//----------------->

	// write your codes here only
	




	//<----------------
	

	return day;
}







//#############################################################################
int main(int argc, char **argv)
{
	int year, n_th;
	if (argc != 1)
	{
		printf("USAGE: ] ret\n");
		exit(0);
	}

	year = 2017; n_th=1;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


	year = 2017; n_th=2;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


	year = 2017; n_th=10;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


	year = 2017; n_th=20;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


}


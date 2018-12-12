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
    struct tm init[12];
    struct tm *after[12];
    struct tm *formday[12];
    int mday[12],wday[12],i;

	int day=0;
    time_t init_time[12];
    time_t second_time[12];

    for(i=0;i<12;i++){
        memset(&init[i],0,sizeof(struct tm));
        init[i].tm_year=year-1900;
        init[i].tm_mon=i;
        init[i].tm_mday=1;
        init_time[i]=mktime(&init[i]);
        after[i]=localtime(&init_time[i]);
        wday[i]=after[i]->tm_wday;
        memset(&init[i],0,sizeof(struct tm));
        init[i].tm_year=year-1900;
        init[i].tm_mon=i+1;
        init[i].tm_mday=1;
        second_time[i]=mktime(&init[i])-1;
        formday[i]=localtime(&second_time[i]);
        mday[i]=formday[i]->tm_mday;
    }
    int count=0;

        printf("%d\n",after[0]->tm_mday);
    int j=0;
    for(i=0;i<12;i++){
        for(j=1;j<=mday[i];j++){
            if(after[i]->tm_wday==0){
                count++;
                if(count==n_th){
                    return day;
                }
            }
            after[i]->tm_mday++;
            init_time[i]=mktime(after[i]);
            after[i]=localtime(&init_time[i]);
            if(after[i]->tm_wday==0){
                count++;
                if(count==n_th){
                    return day;
                }
            }
        day+=j+1;
        }
    }
	
	

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


	year = 2017; n_th=3;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


	year = 2017; n_th=20;
	printf("The first sunday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year, n_th));


}


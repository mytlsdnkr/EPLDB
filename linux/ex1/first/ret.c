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
int get_the_n_th_sunday_of_the_year(int year,int month, int n_th)
{

    int day;
    struct tm init;
    struct tm *after;
    struct tm *formday;
    int mday,wday;

    time_t init_time;
    time_t second_time;
    memset(&init,0,sizeof(struct tm));
    init.tm_year=year-1900;
    init.tm_mon=month-1;
    init.tm_mday=1;
    init_time=mktime(&init);
    after=localtime(&init_time);
    wday=after->tm_wday;
    memset(&init,0,sizeof(struct tm));
    init.tm_year=year-1900;
    init.tm_mon=month;
    init.tm_mday=1;
    second_time=mktime(&init)-1;
    formday=localtime(&second_time);

    mday=formday->tm_mday;

    int k=1,j,count=0;

    printf("무슨 요일이야?%d\n",wday);
    printf("무슨 요일이야?%d\n",mday);
    for(k;k<=mday;k++,wday++){
        if(wday%7==6){
            break;
            
        }



    }
    count=0;

    for(k;k<=mday;k+=7){
        count++;
        if(count==n_th){
            day=k;
            break;
            
        }

        

    }
	return day;
}







//#############################################################################
int main(int argc, char **argv)
{
	int year, n_th,month;
	if (argc != 1)
	{
		printf("USAGE: ] ret\n");
		exit(0);
	}

	year = 2018; month=4,n_th=2;
	printf("The first saturday of %04d_%02d is [%2d]\n", year, n_th, get_the_n_th_sunday_of_the_year(year,month, n_th));


}


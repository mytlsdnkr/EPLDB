#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>


//I:	Complete the print_calendar() which print the calendar of a given month and  year.
//		The below is an example output of print_calendar(2016, 8).
//
//
//	               8 2021 
//		Sun  Mon  Tue  Wed  Thu  Fri  Sat
//		 1    2    3    4    5    6    7
//		 8    9   10   11   12   13   14
//		15   16   17   18   19   20   21
//		22   23   24   25   26   27   28
//		29   30   31

// The print_calendar() is equivalent to the Linux command cal, as follows.
// ] cal 8 2021
//


//#############################################################################
// complete this function
void print_calendar(int year, int month)
{

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



    printf("\t\t%d월\t%d\t\n",after->tm_mon+1,after->tm_year+1900);
    printf("일\t월\t화\t수\t목\t금\t토\n");
    
    int i=0;
    for(i=0;i<wday;i++){
        printf("\t");
    }
    int k=1,line=0,count=0;
    int j=k;
    for(k;k<=mday;k++){
        if(line==0){
            for(j;j<=7-wday;j++){
                printf("%d\t",j);
            }
            printf("\n");
            line++;
            k=j;
        }
        printf("%d\t",k);
        count++;
        if(count%7==0){
            printf("\n");
           // count=0;
        }

    }

    printf("\n");









}



//#############################################################################
int main(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("USAGE: ] ret\n");
		exit(0);
	}

	print_calendar(2018,11);
    print_calendar(2022,11);
    print_calendar(2013,5);

}


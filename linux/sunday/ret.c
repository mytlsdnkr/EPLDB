#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>


//I:	Complete the sum_sunday() which returns the date sum of all Sundays in a given year.
//		The return value of date_sum(2016) is 829.
//		829 = (3+10+17+24+31) + (7+14+21+28) + ... + (4+11+18+25)
//
//							2016                               
//
//         1월                    2월                    3월        
// 일 월 화 수 목 금 토   일 월 화 수 목 금 토   일 월 화 수 목 금 토
//                 1  2       1  2  3  4  5  6          1  2  3  4  5
//  3  4  5  6  7  8  9    7  8  9 10 11 12 13    6  7  8  9 10 11 12
// 10 11 12 13 14 15 16   14 15 16 17 18 19 20   13 14 15 16 17 18 19
// 17 18 19 20 21 22 23   21 22 23 24 25 26 27   20 21 22 23 24 25 26
// 24 25 26 27 28 29 30   28 29                  27 28 29 30 31
// 31
//          4월                    5월                    6월        
// 일 월 화 수 목 금 토   일 월 화 수 목 금 토   일 월 화 수 목 금 토
//                 1  2    1  2  3  4  5  6  7             1  2  3  4
//  3  4  5  6  7  8  9    8  9 10 11 12 13 14    5  6  7  8  9 10 11
// 10 11 12 13 14 15 16   15 16 17 18 19 20 21   12 13 14 15 16 17 18
// 17 18 19 20 21 22 23   22 23 24 25 26 27 28   19 20 21 22 23 24 25
// 24 25 26 27 28 29 30   29 30 31               26 27 28 29 30
// 
//          7월                    8월                    9월        
// 일 월 화 수 목 금 토   일 월 화 수 목 금 토   일 월 화 수 목 금 토
//                 1  2       1  2  3  4  5  6                1  2  3
//  3  4  5  6  7  8  9    7  8  9 10 11 12 13    4  5  6  7  8  9 10
// 10 11 12 13 14 15 16   14 15 16 17 18 19 20   11 12 13 14 15 16 17
// 17 18 19 20 21 22 23   21 22 23 24 25 26 27   18 19 20 21 22 23 24
// 24 25 26 27 28 29 30   28 29 30 31            25 26 27 28 29 30
// 31
//         10월                   11월                   12월        
// 일 월 화 수 목 금 토   일 월 화 수 목 금 토   일 월 화 수 목 금 토
//                    1          1  2  3  4  5                1  2  3
//  2  3  4  5  6  7  8    6  7  8  9 10 11 12    4  5  6  7  8  9 10
//  9 10 11 12 13 14 15   13 14 15 16 17 18 19   11 12 13 14 15 16 17
// 16 17 18 19 20 21 22   20 21 22 23 24 25 26   18 19 20 21 22 23 24
// 23 24 25 26 27 28 29   27 28 29 30            25 26 27 28 29 30 31
// 30 31


// Due: 2018-11-06 12:00


//#############################################################################
// complete this function
int sum_sunday(int year)
{
    int sum = 0;

    struct tm init[12];
    struct tm *after[12];
    struct tm *formday[12];
    int mday[12],wday[12],i;

    time_t init_time[12];
    time_t second_time[12];

    for(i=0;i<12;i++){

        memset(&init[i],0,sizeof(struct tm));
        init[i].tm_year=year-1900;
        init[i].tm_mon=i+1-1;
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

    int s=0;
    i=0;
    for(s=0;s<12;s++){
    int k=1,line=0,count=0;
    int j=1;
    for(k;k<=mday[s];k++){
        if(line==0){
            if(wday[s]==0){
                sum++;
            }
            for(j;j<=7-wday[s];j++){
            }
            line++;
            k=j;
            sum+=j;
        }
        count++;
        if(count%7==0){
            if(k!=mday[s]){

            sum+=k+1;
            }
           count=0;
        }

    }


    }


    return sum;

}



//#############################################################################
int main(int argc, char **argv)
{
    int year;

    if (argc != 1)
    {
        printf("USAGE: ] ret\n");
        exit(0);
    }

    year=2016; printf("Year:%d = %d\n", year, sum_sunday(year));
    year=2015; printf("Year:%d = %d\n", year, sum_sunday(year));
    year=2017; printf("Year:%d = %d\n", year, sum_sunday(year));
    year=2019; printf("Year:%d = %d\n", year, sum_sunday(year));
    year=2021; printf("Year:%d = %d\n", year, sum_sunday(year));
    year=2023; printf("Year:%d = %d\n", year, sum_sunday(year));
}


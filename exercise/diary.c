#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){

    char filename[20];
    char str[2048];
    int in;
    int key;

    struct tm *tm_ptr;
    time_t the_time;

    (void)time(&the_time);

    tm_ptr=gmtime(&the_time);

    sprintf(filename,"%02d_%02d_%02d.txt",tm_ptr->tm_year+1900,tm_ptr->tm_mon+1,tm_ptr->tm_mday);

    in=open(filename,O_WRONLY|O_CREAT,0777);
    int i=0;
    while(1){

        key=getchar();
        str[i]=key;
        i++;

        if(key=='\n'){
            write(in,str,i);
            i=0;
            str[0]='\0';
        }

        if(key==-1){
            break;
        }



    }


    close(in);




    exit(0);

}

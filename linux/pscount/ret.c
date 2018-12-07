#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


//#############################################################################
// Request: Complete the following functions. 
// Due    : Nov. 12, 2018 24:00
//#############################################################################



//#############################################################################
// Complete this function which counts the number of processes running on the system
// ] ls /proc | grep ^[0-9] | wc | awk '{print $1}'
// ] ps axh | wc | awk '{print $1}'
// ] ps axh | wc -l
// ] watch -n 1 'ls /proc | grep ^[0-9] | wc -l'
// ] watch -n 1 'ps axh | wc -l'
int process_count()
{

	int count=0;

    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;



    if((dp=opendir("/proc"))==NULL){
        fprintf(stderr,"cannot open directory:/proc\n");
        return;
    }


    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){

            if(entry->d_name[0]>='A' && entry->d_name[0]<='Z' || entry->d_name[0]>='a' && entry->d_name[0]<='z'){
                continue;
            }else{
                if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0){
                    continue;
                }
                count++;
            }
            

        }   
    }
    closedir(dp);


	return count;
}




//#############################################################################
int main(int argc, char **argv)
{
	int count = 0;

	if (argc != 1)
	{
		printf("USAGE: ] ret \n");
		exit(0);
	}

    printf("%d\n",process_count());

	// ---------------------------------------------

}


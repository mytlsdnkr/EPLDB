#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>



//#############################################################################
// Request: Complete the following program. 
// Due    : 2018-10-30 12:00
//#############################################################################


//  Complete the following C program which print out the max depth from the given dir.

// ] ./ret .
// ] Max Depth = 14

// ] ./ret /home
// ] Max Depth = 14

// good luck!
//

int count=0;
int max=0;


void printdir(char *dir){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp=opendir(dir))!=NULL){
        fprintf(stderr,"cannot open direcotry: %s\n",dir);
        return;
    }
    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name))
                continue;
            chdir(entry->d_name);
            count++;
            printdir(entry->d_name);
            
        }

    }



}


//#############################################################################
int main(int argc, char **argv)
{

    char *topdir=".";

    if (argc >=2)
        topdir=argv[1];


    if(argc != 2)
    {
        printf("Usage: ] ./ret <dirname>\n");
        exit(1);
    }

    printdir(topdir);

    printf("Execution finished successfully.... \n\n");
    exit(EXIT_SUCCESS);
}


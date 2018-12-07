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
#include <sys/types.h>



//#############################################################################
// Request: Complete the following program. 
// Due    : 2018-10-16 12:00
//#############################################################################


// Implement the following shell command using directory system calls 
// ] mkdir a/b/c/d/e/f/g/h/i/j/k/l/m/n -p
//
//
// ] ls -R a
// ] tree a

// good luck!

	
//#############################################################################
int main(int argc, char **argv)
{
	char path[] = "a/b/c/d/e/f/g/h/i/j/k/l/m/n";
    
    char *beforpath=strtok(path,"/");

    while(beforpath!=NULL){
        mkdir(beforpath,0777);
        chdir(beforpath);

        beforpath=strtok(NULL,"/");



    }


	printf("Execution finished successfully.... \n\n");
    exit(EXIT_SUCCESS);
}


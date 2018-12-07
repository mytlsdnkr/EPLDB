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
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





//#############################################################################
// Request: Complete the following functions. 
// Due    : Dec. 04, 2018 12:00
//#############################################################################


//#############################################################################
// Complete a program which executes the following shell commands.
// ] ls -l | wc
// 1. Implement it by using two popen() pipe functions.
// 2. execute each command by using seperate popen(). 
//		a popen() for 'ls' command, the other popen() for 'wc' command.



//#############################################################################
int main(int argc, char **argv)
{

   	int res, i;
	if (argc != 1)
	{
		printf("USAGE: ] ./ret \n");
		exit(EXIT_FAILURE);
	}
	int process_count = 1;

    FILE *read_fp,*write_fp;
    char buffer[2048];

    memset(buffer,'\0',sizeof(buffer));

    read_fp=popen("ls -l ","r");
    write_fp=popen("wc","w");

    if(read_fp!=NULL){
            process_count=fread(buffer,sizeof(char),2048,read_fp);
        if(process_count>0){
            fwrite(buffer,sizeof(char),process_count,write_fp);
            buffer[0]='\0';

        }
        pclose(read_fp);
        pclose(write_fp);
            
    }








	// ---------------------------------------------


	printf("Execution finished successfully.... \n");
    exit(EXIT_SUCCESS);

}



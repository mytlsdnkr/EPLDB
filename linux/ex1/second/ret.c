
/*
Q. Complete a program which retrieves the parent process ID of a target process. 
   The target process ID is given in the first input argument of the program.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>



//#############################################################################
pid_t getParentProcessID(pid_t pid)
{
	pid_t ppid = 0;
    char path[100];
    char block[20];
    char buf[5];
    int in;

    sprintf(path,"/proc/%d",pid);

    chdir(path);

    in=open("stat",O_RDONLY);

    read(in,block,sizeof(block));

    int i,j=0;
    int count=0;
    int len=strlen(block);


    for(i=0;i<len;i++){
        if(count==3){
            while(block[i]!=' '){
                buf[j++]=block[i];
                break;
            }
        }
        if(block[i]==' '){
            count++;
        }

    }


    ppid=atoi(buf);

    

    




    








    

    

	// start of your code .........................



	// end of your code ...........................

	return ppid;
}



//#############################################################################
int main(int argc, char **argv)
{
	pid_t	pid, ppid;

	if (argc != 2)
	{
		printf("USAGE: ./ret [PID] \n");
		exit(0);
	}

	pid = atoi(argv[1]);

	ppid = getParentProcessID(pid);

	if(ppid)
		printf("PPID of the process with PID[%d] is %d \n\n", pid, ppid); 
	else
		printf("The process with PID[%d] is not running\n\n", pid); 

	exit(EXIT_SUCCESS);
}


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
#include <wait.h>


//#############################################################################
// Request: Complete the following functions. 
// Due    : Nov. 13, 2018 18:00
//#############################################################################



//#############################################################################
// Complete this function which executes "find" command simultaneously.
// 
// For example, when you execute this program with the command line "]./ret /etc httpd* *xml web*"
// This program executes three "find" programs simultaneously
//	] find /etc -name httpd* &
//	] find /etc -name *xml &
//  ] find /etc -name web* &
//  
// You should use fork() and exec() system calls to create child processes.
// 
// On completion of the multiple concurrent execution of the find command,
// This program print out the PIDs and Exitcodes of child processes.
//
int main(int argc, char **argv)
{
	int i;
    int stat_val;
    pid_t child_pid;
	if (argc < 3)
	{
		printf("USAGE  : ] ./ret [dir_path] [search pattern list]\n");
		printf("Example: ] ./ret /home  ret.c Makefile ");
		printf("Example: ] ./ret /etc  httpd* *xml web*\n ");

		exit(0);
	}

	for(i=2; i<argc; i++)
		printf("search word %2d = [%s]\n", i, argv[i]);
    pid_t pid;

    


    for(i=0;i<argc-2;i++){
        pid=fork();
        if(pid>0){
        }
        if(pid==0){

            execl("find",argv[1],"-name",argv[i+2],(char *)0);
        }
    }
   
            child_pid=wait(&stat_val);
            printf("Child has finished:PID=%d exitedcode:%d\n",child_pid,WEXITSTATUS(stat_val));

	printf("All child processes finished successfully.... \n");
    exit(0);

                



	return 1;
}


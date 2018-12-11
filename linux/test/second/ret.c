
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



//#############################################################################
pid_t getParentProcessID(pid_t pid)
{
	pid_t ppid = 0;

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


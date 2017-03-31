
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int critical_section (int loop_limit, int who_called)
{
	int flag;

	for (loop limit)
	{
		printf (who_called, loop index);
	}
	printf (“returning to caller process x”); //x is the caller process
	return 0;
}




int main()
{


	pid_t pid;
	int status, flag;
	int fd[2];
	int pipe = pipe(fd);



	for (int i = 0; i < 9; i++)
	{
		pid = fork();
	}



	//pipe error
	if (p1 < 0)
 	{
		perror("pipe error");
    		exit(-1);
 	} 


	//fork error
	if (pid < 0)
	{
  		perror("fork");
 		printf("main function: errno number is %d\n",errno);
		exit(pid1);
	}

	//child
	else if (pid == 0)
	{
		//enter critical section
	}






	return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

//This is the critical region method
//loop_limit is the number of iterations
//who_called is the process that called the critical_section
int critical_section (int loop_limit, int who_called)
{
	int loop_index = 0;
	while (loop_index < loop_limit)
	{
		printf("%d called the critical region with index %d\n", getpid(),  loop_index);
		loop_index++;
	}
	printf("Returning to caller process %d\n", getpid()); //x is the caller process
	return 0;
}



//main method
int main()
{
	pid_t pid;		//process id
	int fd[2];		//name of pipe
	int p1 = pipe(fd);	//create the pipe
	int i, flag;		//useful variables

	//Handle pipe error
        if (p1 < 0)
        {
                perror("pipe error");
                exit(-1);
        }
	
	//Create semaphore in pipe
	int semaphore = 1;
	write(fd[1], &semaphore, sizeof(semaphore));

	//Create multiple processes using fork()
	for (i = 0; i < 9; i++)
	{
		pid = fork();
		//If child, exit this loop so only parent creates processes
		if(pid == 0)
		{
			break;
		}

		//Handle fork error
	        if (pid < 0)
       	 	{
        	        perror("fork");
                	printf("main function: errno number is %d\n",errno);
        	}
	}
	
	
	int goThrough = 1;	
	while (goThrough = 1)
	{	
		//wait ensures only one process at a time
		wait(NULL);
		
		//Processes read from pipe and adjusts semaphore in pipe
		read(fd[0], &flag, sizeof(flag));
		flag--;
		write(fd[1], &flag, sizeof(flag));

		//enter critical section if semaphore is 0
		if (flag == 0)
		{
			//call critical section method
			critical_section (20, getpid());
			
			//readjust semaphore in pipe to indicate completion to the other processes
			flag++;
			write(fd[1], &flag, sizeof(flag));
			//once done, break out so we do not revisit critical section
			break;
			
		}
		
	}
	//Indicate completion to the screen
	printf("I'm done %d\n\n", getpid());

	return 0;
}


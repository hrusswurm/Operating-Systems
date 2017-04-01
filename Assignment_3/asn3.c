
#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


//loop_limit is the number of iterations
int critical_section (int loop_limit, int who_called)
{
	//for (loop limit)
	int loop_index = 0;
	while (loop_index < loop_limit)
	{
		printf("%d called the critical region with index %d \n", getpid(),  loop_index);
		loop_index++;
	}
	printf("returning to caller process x"); //x is the caller process
	return 0;
}




int main()
{
	pid_t pid;
	int status;
	int fd[2];
	int p1 = pipe(fd);
	int i;int flag;

	//pipe error
        if (p1 < 0)
        {
                perror("pipe error");
                exit(-1);
        }
	
	int semaphore = 1;
	write(fd[1], &semaphore, sizeof(semaphore));
	for (i = 0; i < 9; i++)
	{
		pid = fork();
		if(pid == 0)
		{
			break;
		}
		//fork error
	        if (pid < 0)
       	 	{
        	        perror("fork");
                	printf("main function: errno number is %d\n",errno);
        	}
	}

	int goThrough = 1;	
	while (goThrough = 1)
	{
		wait(NULL);
		//printf("I'm waiting %d\n", getpid());
		read(fd[0], &flag, sizeof(flag));
		flag--;
		write(fd[1], &flag, sizeof(flag));

		if (flag == 0)
		{
			//enter
			critical_section (1, getpid());
			
			flag++;
			write(fd[1], &flag, sizeof(flag));
			break;
			
		}
		
	}

	printf("I'm done %d\n", getpid());


	wait(NULL);
	return 0;
}



#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>




int main(){


pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9;
int status;

pid1 = fork();

//fork error
  if (pid1 < 0)
  {
  	perror("fork");
 	printf("main function: errno number is %d\n",errno);
	exit(pid1);
  }

if (pid1 != 0)
{
  	printf("From parent process %d Child_1 created with PID: %d\n", getpid(), pid1);
}














return 0;
}


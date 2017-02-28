#include <sys/types.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
int fd[2];
int fd1[2];
int x, y;

pid_t pid;
ssize_t numRead;

int p1 = pipe(fd);
int p2 = pipe(fd1);

pid = fork();

//error piping
if (p1 < 0 || p2 < 0){
    perror("pipe error");
    exit(-1);
  }


//error forking
if (pid<0) {
	perror("Problem forking");
	exit(-1);
}

//parent
else if (pid>0) 
{
	printf("A pipe is created for communication between parent and child.\n");
	
	printf ("From parent %d Reading X from User (Please enter integer X)\n", getpid());
 	scanf ("%d", &x);	
	
	close(fd1[0]);
	printf("From parent %d: writing X to the pipe (Please wait a moment).\n", getpid());
	write(fd1[1], &x, sizeof(x));	

	wait(NULL);
        
        read(fd[0], &y, sizeof(y));
	printf("From parent %d, the value of y is: %d\n", getpid(), y);
}

//child
else 
{	
	sleep(10);
	printf("From parent %d, child with PID %d is created.\n", getppid(), getpid());

	printf("From child: Reading Y from user (Please enter integer Y)\n");
        scanf ("%d", &y);

	close(fd[0]);
	printf("From child: writing Y to the pipe.\n");
        write(fd[1], &y, sizeof(y));

	read(fd1[0], &x, sizeof(x));
	printf("From child: reading X from the pipe.\n");
	printf("From child: The value of x is: %d\n", x);
		
}

return 0;
}

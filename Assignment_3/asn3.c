
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

int main(){


pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9;
int status;
int flag;

int fd[2];
int pipe = pipe(fd);

//pipe error
if (p1 < 0)
 {
    perror("pipe error");
    exit(-1);
 } 


pid1 = fork();

//fork error
if (pid1 < 0)
{
  	perror("fork");
 	printf("main function: errno number is %d\n",errno);
	exit(pid1);
}

//child1
else if (pid1 == 0)
{

}



pid2 = fork();

//fork error
if (pid2 < 0)
{
        perror("fork");
        printf("main function: errno number is %d\n",errno);
        exit(pid1);
}

//child2
else if (pid2 == 0)
{

}







return 0;
}


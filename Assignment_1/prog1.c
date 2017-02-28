

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


//MAIN
int main()
{ 
  pid_t pid1, pid2, pid3, child_1_1 ;  
  pid1 = fork();
      
  int status;

  if (pid1 != 0){
  	printf("From parent process %d Child_1 created with PID: %d\n", getpid(), pid1);
  }
 
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
        //child makes a child
        child_1_1=fork();
        if (child_1_1 == 0){
        	exit(child_1_1);
        }
	printf("From Child1: Child1.1 created with PID: %d\n", child_1_1);

  exit(getpid());
  }

  pid2 = fork();

  //parent  
  if (pid2 != 0)
  {
   	printf("From parent process %d Child_2 created with PID: %d\n", getpid(), pid2);
	printf("Waiting for child_2 to complete before creating child_3 \n");
	wait(pid2);

  }
  
  pid3 = fork();
  
  //parent  
  if ((pid2 != 0) && (pid1 != 0) && (pid3 != 0))
  {
	printf("From parent process %d Child_3 created with PID: %d\n", getpid(), pid3);
  }   

  if (pid2 ==0)
  {
	exit(getpid());
  }

 
  if (pid3 == 0)
  {
	printf("From child_3: Calling an external program B.out and leaving child_3... \n");
	execlp("./B", "B", NULL);	  	
  }



  return 0;
}




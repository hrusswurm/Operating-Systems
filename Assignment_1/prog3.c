

#include <sys/types.h>  // (pid_t typedef)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int fd[2];
  pid_t pid; 

  int p1 = pipe(fd);

  //pipe error
  if (p1 < 0)
  {
    perror("pipe error");
    exit(-1);
  } 
  
  pid = fork();
  
  //fork error
  if (pid < 0) 
  {
    perror("fork error");
    exit(-1);
  }
  
  // parent
  if(pid > 0)
  {
   // perform <stdout> redirection here
   dup2(fd[1], STDOUT_FILENO);
   close(fd[1]);
  
   // execute ls -l command
   execlp("ls", "ls", "-l", NULL);
  }


  else //child (pid == 0)
  {
    // perform <stdin> redirection
   dup2(fd[0], STDIN_FILENO);
   close(fd[0]);    

    // execute grep command
   execlp("grep", "grep", "xxxx", NULL);
  }


  return 0;

}



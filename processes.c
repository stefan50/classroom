#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
  int res = 0;
  int status;
  pid_t pid = fork();
  if(pid == -1)
  {
    perror("fork");
  }
  //printf("%d\n", getpid());
  if(!pid)
  {
    res = execvp(argv[1], argv+1);

    if(res == -1)
    {
      perror("execvp");
      abort();
    }
  }
  else
  {
    wait(&status);
    if(!WIFSIGNALED(status))
    {
      printf("I am the parent, see? PID: %d\n", getpid());
    }
    else if(WCOREDUMP(status))
    {
      printf("Core dumped!\n");
    }
  }

  return 0;
}

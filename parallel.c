#include "stdio.h"
#include <unistd.h>
#include <sys/wait.h>

char* arguments[8] = {"ls",NULL,"df",NULL,"ps",NULL,"pwd",NULL};

int main(int argc, char const *argv[]) {
  for (int i = -1; i < 7; i++) {
    i++;
    int status = fork();

    if (status == 0) {
      execvp(arguments[i],arguments);
    }
    else{
      waitpid(-1,&status,0);
    }
    printf("\n");
  }
  return 0;
}

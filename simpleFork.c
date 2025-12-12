#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (void) {
    // process id
    int pid,i,endvalue;
    // use fork to create a new process
    endvalue=10;
    printf("calling fork()\n");
    pid=fork();
    // check to see if fork worked
    if (pid<0) {
       printf("Fork failed\n");
       exit(0);
    }
    else if (pid == 0) {
            // in child process
            for (i=0; i<endvalue; i++) {
                printf("Child\n");
                fflush(stdout);
            }
    }
    else {
          // parent process
          wait(NULL);
          for (i=0; i<endvalue; i++) {
              printf("Parent\n");
              fflush(stdout);
          }
          printf("Child Complete\n");
          exit(0);

    }
}

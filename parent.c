// Parent Program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <signal.h>
#include <errno.h>

int main(void)
{
    pid_t pid;
    int status;
    
    if((pid = fork()) < 0)
    {
        // probably out of processes
        status = -1;
    }
    else if (pid == 0)
    {
        // in child so we execute process
        // use the execl function to to run a shell an execute the child program
        execl("/bin/sh", "sh", "-c", "./child", (char *)0);
    }
    
    while(1)
    {
        sleep(1);
        printf("Parent");
        fflush(stdout);
    }
    printf("end of program");
}

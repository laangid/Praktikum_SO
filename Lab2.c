#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pid;
    
    printf("Hello World!\n");
    printf("I am the parent process and pid is %d\n", getpid());
    printf("Here i am before use of forking\n");
    
    pid = fork(); /* Menyimpan hasil fork ke variabel pid */
    
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("Here I am just after forking\n");
    
    if (pid == 0) {
        /* Jika pid 0, ini adalah kode untuk CHILD */
        printf("I am the child process and pid is %d.\n", getpid());
    } else {
        /* Jika pid > 0, ini adalah kode untuk PARENT */
        printf("I am the parent process and pid is: %d\n", getpid());
    }
    
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    return 0;
}

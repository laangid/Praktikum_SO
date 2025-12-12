#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> /* Library untuk fungsi wait */

int main(void)
{
    int pid;
    int status;

    printf("Hello World!\n");

    pid = fork();

    if (pid == -1) /* Kondisi jika fork error */
    {
        perror("bad fork");
        exit(1);
    }

    if (pid == 0) {
        /* Kode untuk Child */
        printf("I am the child process.\n");
    } else {
        /* Kode untuk Parent */
        wait(&status); /* Parent menunggu child selesai di sini */
        printf("I am the parent process.\n");
    }

    return 0;
}

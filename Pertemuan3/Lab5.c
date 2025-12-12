#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int forkresult;

    printf("%d: I am the parent. Remember my number!\n", getpid());
    printf("%d: I am now going to fork \n", getpid());

    forkresult = fork();

    if (forkresult != 0) {
        /* Proses PARENT mengeksekusi kode ini */
        printf("%d: My child's pid is %d\n", getpid(), forkresult);
    }
    else {
        /* Proses CHILD mengeksekusi kode ini */
        printf("%d: Hi! I am the child.\n", getpid());
    }

    /* Baris ini di luar if-else, jadi dijalankan oleh keduanya */
    printf("%d: like father like son. \n", getpid());

    return 0;
}

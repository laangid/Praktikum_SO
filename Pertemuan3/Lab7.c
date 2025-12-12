#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;
    
    pid = fork();
    
    if (pid != 0) {
        /* KODE PARENT */
        /* Parent sengaja looping selamanya dan TIDAK melakukan wait() */
        while (1) {
            sleep(100);
        }
    }
    else {
        /* KODE CHILD */
        /* Child langsung mati (exit) */
        exit(42); 
    }
    return 0;
}

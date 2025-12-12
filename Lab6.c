#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> /* Untuk fungsi sleep */

int main()
{
    int pid;
    
    printf("I'am the original process with PID %d and PPID %d.\n", getpid(), getppid());
    
    pid = fork(); /* Duplikasi proses */
    
    if (pid != 0) {
        /* KODE PARENT */
        printf("I'am the parent with PID %d and PPID %d.\n", getpid(), getppid());
        printf("My child's PID is %d\n", pid);
        printf("PID %d terminates.\n", getpid());
        /* Parent langsung selesai (mati) di sini */
    }
    else {
        /* KODE CHILD */
        sleep(4); /* Child tidur 4 detik untuk memastikan Parent mati duluan */
        
        /* Saat bangun, Parent aslinya sudah mati. Cek siapa PPID barunya */
        printf("I'm the child with PID %d and PPID %d.\n", getpid(), getppid());
        printf("PID %d terminates.\n", getpid());
    }

    return 0;
}

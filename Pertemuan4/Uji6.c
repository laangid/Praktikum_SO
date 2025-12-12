#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
    int number=0, statval; /* sinyal yang dikirim child ditangkap oleh statval [cite: 213, 214] */
    
    printf ("%d: I'm the parent !\n", getpid () );
    printf ("%d: number = %d\n", getpid ( ), number);
    printf ("%d: forking! \n", getpid ( ) );
    
    if (fork() == 0) /* Child Process */
    {
        printf ("%d: I'm the child !\n", getpid());
        printf ("%d: number = %d\n", getpid(), number);
        printf ("%d: Enter a number: ", getpid ( ));
        scanf ("%d", &number);
        printf ("%d: number = %d\n", getpid(), number);
        printf ("%d: exiting with value %d\n", getpid(), number);
        exit (number);
    } 
    /* Parent Process melanjutkan dari sini */
    
    printf ("%d: number = %d\n", getpid(), number);
    printf ("%d: waiting for my kid!\n", getpid ( ) );
    
    wait (&statval); /* Menunggu child [cite: 234] */
    
    printf("statval = %d\n", statval);
    
    if (WIFEXITED (statval))
    {
        printf ("%d: my kid exited with status %d\n", 
                getpid(), WEXITSTATUS (statval));
    }
    else
    {
        printf ("%d: My kid was killed off!! \n", getpid ( ));
    }
}

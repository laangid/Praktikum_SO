#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
    int forkresult;
    
    printf ("%d: I am the parent. Remember my number!\n", getpid());
    printf ("%d: I am now going to fork .. \n", getpid());
    
    forkresult = fork();
    
    if (forkresult != 0)
    { /* parent akan mengeksekusi kode ini [cite: 194] */
        printf ("%d: My child's pid is %d\n", getpid(), forkresult);
    }
    else /* forkresult == 0 */
    { /* child akan mengeksekusi kode ini [cite: 198] */
        printf ("%d: Hi! I am the child.\n", getpid());
        printf ("%d: I'm now going to exec ls!\n\n\n", getpid());
        
        execlp ("ls", "ls", NULL);
        
        printf ("%d: AAAAH!! My EXEC failed!!!!\n", getpid());
        exit (1);
    }
    
    printf ("%d: like father like son. \n", getpid ( ) );
}

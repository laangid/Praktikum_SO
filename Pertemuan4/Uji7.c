#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main ()
{
    int howmany, status, whichone, child1, child2;

    if ((child1 = (int) fork()) == 0) /* Parent melahirkan child ke-1 [cite: 255] */
    {
        printf("Hi, I am the first child, my ID is %d, and my parent ID is %d\n", getpid(), getppid());
        sleep (10); /* Tidur 10 detik */
        printf("\nexiting first child\n");
        exit(0);
    }
    else if (child1 == -1)
    {
        perror("1st fork: something went wrong\n");
        exit(1);
    }

    if ((child2 = (int) fork()) == 0) /* Parent melahirkan child ke-2 [cite: 266] */
    {
        printf("Hi, I am the second child, my ID is %d, and my parent ID is %d\n", getpid(), getppid());
        sleep (5); /* Tidur 5 detik */
        printf("\nexiting second child\n");
        exit(0);
    }
    else if (child2 == -1)
    {
        perror ("2nd fork: something went wrong\n");
        exit(1);
    }

    printf ("This is parent, my ID is %d\n", getpid());
    howmany = 0;

    while (howmany < 2) /* Wait Twice [cite: 278] */
    {
        whichone = (int) wait(&status);
        howmany++;
        
        printf("whichone id %d\n", whichone);
        printf("child1 id %d\n", child1);
        printf("child2 id %d\n", child2);
        
        if (whichone == child1)
        {
            printf ("First child exited\n");
        }
        else if (whichone == child2)
        {
            printf ("Second child exited\n");
        }
        else
        {
            printf ("not child exited\n");
        }
        
        printf ("whichone = %d\n", whichone);
        
        if ((status & 0xffff) == 0)
        {
            printf ("correctly\n");
        }
        else
        {
            printf ("uncorrectly\n");
        }
    }
    
    printf ("\nParent terminated\n");
    return 0;
}

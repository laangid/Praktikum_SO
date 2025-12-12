#include <stdio.h>
#include <unistd.h> /* Library untuk fork */

int main(void)
{
    printf("Hello World\n");
    fork(); /* Disinilah proses membelah diri */
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("I am after forking\n");
    printf("\tI am process %d.\n", getpid());
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    return 0;
}

// Child Program
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    while(1)
    {
        printf("Child");
        fflush(stdout);
        sleep(1);
    }
}

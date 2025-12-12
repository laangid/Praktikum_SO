#include <stdio.h>
#include <unistd.h>

int main ()
{
    execl ("/bin/ls", /* program yang dimuat berikan secara full path [cite: 134] */
           "ls",      /* nama program yang akan dikirim ke argv[0] [cite: 135] */
           "-l",      /* parameter pertama (argv[1]) [cite: 136] */
           "-a",      /* parameter kedua (argv[2]) [cite: 137] */
           NULL);     /* terminasi arg list [cite: 138] */
    printf ("EXEC Failed\n"); // Baris ini akan dicetak saat terdapat kesalahan [cite: 141]
}

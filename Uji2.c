#include <stdio.h>
#include <unistd.h>

int main ()
{
    execlp ("ls",      /* program yang dimuat PATH dicari  */
            "ls",      /* nama program yang akan dikirim ke argv[0] [cite: 150] */
            "-l",      /* parameter pertama (argv[1]) [cite: 151, 152] */
            "-a",      /* parameter kedua (argv[2]) [cite: 153] */
            NULL);     /* terminasi arg list [cite: 154] */
    printf ("EXEC Failed\n"); // Baris ini akan dicetak saat terdapat kesalahan [cite: 156]
}

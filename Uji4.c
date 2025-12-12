#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    /* Asumsi: Program dijalankan tanpa argumen, misal: ./Uji4 */

    execvp ("echo", /* program yang dimuat PATH dicari  */
            &argv[0]); /* Argumen dimulai dari elemen 0 array argv */
    
    printf ("EXEC Failed\n"); // Baris ini akan dicetak saat terdapat kesalahan [cite: 178]
}

#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    /* Asumsi: Program dijalankan tanpa argumen, misal: ./Uji3 */
    /* Untuk menjalankan program ini dengan benar, Anda mungkin perlu */
    /* membuat array char* secara eksplisit atau memastikan argv terisi. */
    /* Dalam konteks file Anda: */

    execv ("/bin/echo", /* program yang dimuat hanya full path  */
           &argv[0]);   /* Argumen dimulai dari elemen 0 array argv */
    
    printf ("EXEC Failed\n"); // Baris ini akan dicetak saat terdapat kesalahan [cite: 170]
}

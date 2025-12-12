#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Definisi _REENTRANT memastikan penggunaan library yang thread-safe
#define _REENTRANT

// Fungsi ThreadRoutine yang benar: menerima void *
void *ThreadRoutine(void *arg)
{
    // Mengkonversi (casting) argumen kembali menjadi nilai integer.
    // Menggunakan (long) sebagai perantara aman untuk portability.
    int number = (int)((long)arg); 

    while(1) // loop forever
    {
        // getpid() mengambil PID proses utama, yang sama untuk semua thread
        printf("pid %d : thread %d running\n", getpid(), number);
        sleep(number); // sleep selama 1, 2, 3, atau 4 detik
    }
    return NULL; // Secara teknis tidak akan pernah tercapai karena while(1)
}

int main(void)
{
    int t;
    pthread_t tid[5]; // array untuk melacak 4 thread (indeks 1-4)

    // now loop through and create 4 threads passing t as the parameter
    for (t=1; t<5; t++)
    {
        // Perbaikan: Melewatkan NILAI t, bukan alamat &t, 
        // untuk menghilangkan race condition.
        pthread_create(&tid[t], NULL, ThreadRoutine, (void *)(long)t);
    }

    // now the parent loops and sleeps for 10
    while(1)
    {
        printf("pid %d : parent running\n", getpid());
        sleep(10);
    }
    
    // Perintah exit(1) hanya tercapai jika loop di atas dihentikan secara eksternal (Ctrl+C)
    exit(1); 
}

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define _REENTRANT

// Fungsi ThreadRoutine yang BENAR: menerima void *
void *ThreadRoutine(void *arg)
{
    // Konversi (casting) argumen kembali menjadi nilai integer.
    int number = (int)((long)arg); 
    int i;
    
    // Loop 10 kali (i<10)
    for (i=0; i<10; i++)
    {
        printf("thread %d running, loop %d\n", number, i);
        fflush(stdout); // Memastikan output langsung tercetak
        sleep(number); // sleep selama waktu yang diberikan
    }
    
    // Thread selesai dan mengembalikan NULL
    return NULL; 
}

int main(void)
{
    // t_id1 dan t_id2 adalah variabel tunggal untuk ID thread
    pthread_t tid1, tid2; 

    // now create two thread's
    // Perbaikan Parameter: Melewatkan NILAI 1 dan 2 (bukan alamat int *)
    pthread_create(&tid1, NULL, ThreadRoutine, (void *)(long)1);
    pthread_create(&tid2, NULL, ThreadRoutine, (void *)(long)2);

    // we will now detach thread 1
    // Thread yang di-detach akan otomatis merilis sumber dayanya saat selesai.
    if (pthread_detach(tid1) != 0) {
        perror("Error detaching thread 1");
    } else {
        printf("Thread 1 detached successfully.\n");
    }

    // now try to join thread 1 (ini akan GAGAL karena sudah di-detach)
    printf("Attempting to join thread 1 (detached)...\n");
    if (pthread_join(tid1, NULL) != 0) {
        // pthread_join akan mengembalikan nilai error (misalnya EINVAL) 
        // karena tid1 sudah di-detach
        printf("Unable to join thread 1 (Expected behavior).\n");
    }

    // and now join thread 2 (ini akan BERHASIL)
    printf("Attempting to join thread 2...\n");
    if (pthread_join(tid2, NULL) != 0) {
        perror("Unable to join thread 2");
    } else {
        printf("Thread 2 joined successfully.\n");
    }
    
    printf("parent finished\n");
    exit(0);
}

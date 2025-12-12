#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _REENTRANT

// Fungsi ThreadRoutine yang benar: menerima void *
void *ThreadRoutine(void *arg)
{
    int number = (int)((long)arg); 

    // Pesan mulai
    printf("thread %d running\n", number);
    fflush(stdout); // Pastikan pesan ini segera dicetak
    
    sleep(number); 
    
    // Pesan selesai
    printf("thread %d finish, joining...\n", number);
    fflush(stdout); // Pastikan pesan ini segera dicetak
    
    return NULL;
}

int main(void)
{
    int t;
    pthread_t tid[5]; 

    for (t=1; t<5; t++)
    {
        pthread_create(&tid[t], NULL, ThreadRoutine, (void *)(long)t);
    }

    // Parent menunggu semua thread selesai
    for (t=1; t<5; t++)
    {
        pthread_join(tid[t], NULL);
    }

    // Tambahkan \n ekstra dan fflush di sini untuk memisahkan output akhir dari prompt terminal
    printf("All kids joined, parent running\n\n"); 
    fflush(stdout);
    
    exit(0);
}

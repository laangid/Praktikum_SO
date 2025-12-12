#include <stdio.h>
#include <pthread.h>

int glob_data = 5; // Variabel global

void *kidfunc(void *p)
{
    printf("Kid here. Global data was %d\n", glob_data);
    glob_data = 15;
    printf("Kid Again. Global data was now %d\n", glob_data);
    return NULL; // Ditambahkan return NULL untuk kesesuaian prototipe void*
}

int main ( )
{
    pthread_t kid;
    
    // Perbaikan: Tambahkan pengecekan error saat membuat thread
    if (pthread_create(&kid, NULL, kidfunc, NULL) != 0) {
        perror("Error creating thread");
        return 1;
    }
    
    printf("Parent here. Global data = %d\n", glob_data);
    glob_data = 10; 
    
    // Parent menunggu thread anak selesai
    pthread_join(kid, NULL);
    
    printf("End of program. Global data = %d\n", glob_data);
    return 0;
}

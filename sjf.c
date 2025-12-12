#include <stdio.h>

int main()
{
    // Deklarasi variabel
    // p: process ID, bt: burst time, wt: waiting time, tat: turnaround time
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    // wtavg: average waiting time, tatavg: average turnaround time
    float wtavg, tatavg;

    // Input jumlah proses
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Input Burst Time dan inisialisasi Process ID
    for(i=0; i<n; i++)
    {
        p[i] = i; // Process ID (P0, P1, P2, ...)
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    /* Mengurutkan proses dengan urutan burst time terkecil */
    // Proses pengurutan (Sorting) menggunakan metode Bubble Sort
    for(i=0; i<n; i++)
    {
        for(k=i+1; k<n; k++)
        {
            if(bt[i] > bt[k]) // Jika Burst Time proses ke-i lebih besar dari proses ke-k
            {
                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                // Swap Process ID (penting agar hasil akhir tetap merujuk ke ID asli)
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Inisialisasi proses pertama (indeks 0 - setelah diurutkan)
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    // Menghitung Waiting Time (wt) dan Turnaround Time (tat)
    for(i=1; i<n; i++)
    {
        // Waiting Time proses ke-i
        wt[i] = wt[i-1] + bt[i-1];
        
        // Turnaround Time proses ke-i
        tat[i] = tat[i-1] + bt[i]; // Ekuivalen dengan wt[i] + bt[i]

        // Akumulasi total
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    // Menampilkan hasil
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0; i<n; i++)
    {
        printf("\n\tP%d \t\t%d \t\t%d \t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    // Menampilkan rata-rata
    printf("\n\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f\n", tatavg/n);

    return 0;
}

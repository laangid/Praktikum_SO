#include <stdio.h>

int main()
{
    // Deklarasi variabel
    // bt: burst time, wt: waiting time, tat: turnaround time
    // i, n: loop counter dan number of processes
    int bt[20], wt[20], tat[20], i, n;
    
    // watavg: average waiting time, tatavg: average turnaround time
    float wtavg, tatavg;

    // Input jumlah proses
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Input Burst Time untuk setiap proses
    for(i=0; i<n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Inisialisasi proses pertama (indeks 0)
    // Karena tiba bersamaan, proses pertama tidak perlu menunggu
    wt[0] = wtavg = 0;
    // Turnaround time proses pertama = Burst Time-nya
    tat[0] = tatavg = bt[0];

    // Menghitung Waiting Time (wt) dan Turnaround Time (tat) untuk proses berikutnya
    for(i=1; i<n; i++)
    {
        // Waiting Time (wt) proses ke-i adalah Turnaround Time proses sebelumnya (i-1)
        // Atau, Waiting Time = Waiting Time sebelumnya + Burst Time sebelumnya
        wt[i] = wt[i-1] + bt[i-1];
        
        // Turnaround Time (tat) proses ke-i adalah Waiting Time-nya ditambah Burst Time-nya
        tat[i] = tat[i-1] + bt[i]; // Ekuivalen dengan wt[i] + bt[i]

        // Akumulasi total Waiting Time dan Turnaround Time
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }

    // Menampilkan hasil dalam bentuk tabel
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0; i<n; i++)
    {
        printf("\nP%d \t\t%d \t\t%d \t\t%d", i, bt[i], wt[i], tat[i]);
    }

    // Menampilkan rata-rata
    printf("\n\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f\n", tatavg/n);

    return 0;
}

#include <stdio.h>

int main()
{
    // Deklarasi variabel
    // i, j, n: loop counter dan number of processes
    // bu: remaining burst time (burst time yang akan berkurang)
    // wa: waiting time, tat: turnaround time
    // t: time slice (quantum), ct: original burst time (untuk perhitungan)
    // temp: current time (waktu yang berjalan), max: burst time terbesar
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    
    // awt: average waiting time, att: average turnaround time
    float awt=0, att=0, temp=0;

    // Input jumlah proses
    printf("Enter the no of processes -- ");
    scanf("%d", &n);

    // Input Burst Time
    for(i=0; i<n; i++)
    {
        printf("\nEnter Burst Time for process %d -- ", i+1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; // ct menyimpan burst time original (constant time)
    }

    // Input Time Slice (Quantum)
    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);

    // Temukan burst time terbesar
    max=bu[0];
    for(i=1; i<n; i++)
    {
        if(max<bu[i])
           max=bu[i];
    }

    /* Proses iterasi Round Robin */
    // Loop luar berulang sebanyak max/t + 1 kali untuk memastikan semua proses selesai
    for(j=0; j<(max/t)+1; j++)
    {
        // Loop dalam iterasi pada setiap proses
        for(i=0; i<n; i++)
        {
            // Cek apakah proses masih memiliki remaining burst time
            if(bu[i] != 0)
            {
                // Jika remaining burst time (bu[i]) kurang dari time slice (t)
                if(bu[i] <= t)
                {
                    // Turnaround Time (tat) dicatat saat proses selesai
                    tat[i] = temp + bu[i]; 
                    // Waktu saat ini (temp) diupdate
                    temp = temp + bu[i];
                    // Remaining burst time diset ke 0 (proses selesai)
                    bu[i] = 0;
                }
                // Jika remaining burst time (bu[i]) lebih besar dari time slice (t)
                else // (bu[i] > t)
                {
                    // Remaining burst time dikurangi sebesar time slice
                    bu[i] = bu[i] - t;
                    // Waktu saat ini (temp) diupdate sebesar time slice
                    temp = temp + t;
                }
            }
        }
    }

    // Menghitung Waiting Time dan Total Rata-Rata
    for(i=0; i<n; i++)
    {
        // Waiting Time = Turnaround Time - Original Burst Time (ct)
        wa[i] = tat[i] - ct[i]; 
        
        // Akumulasi total
        att = att + tat[i]; // total turnaround time
        awt = awt + wa[i]; // total waiting time
    }

    // Menampilkan rata-rata
    printf("\n\nThe Average Turnaround time is -- %f", att/n);
    printf("\nThe Average Waiting time is -- %f\n", awt/n);
    
    // Menampilkan hasil dalam tabel
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0; i<n; i++)
    {
        printf("\nP%d \t\t%d \t\t%d \t\t%d", i+1, ct[i], wa[i], tat[i]);
    }
    printf("\n");
    
    return 0;
}

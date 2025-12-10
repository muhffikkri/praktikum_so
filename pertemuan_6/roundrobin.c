/* Round Robin CPU Scheduling Algorithm */
/* Source: Modul Praktikum 5b - Page 4 */

#include<stdio.h>

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;
    
    printf("Enter the no of processes -- ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i+1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; /* Simpan burst time asli ke ct */
    }
    
    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);
    
    max = bu[0];
    for(i=1; i<n; i++) { /* Temukan proses dengan burst time terbesar */
        if(max < bu[i])
            max = bu[i];
    }
    
    /* Simulasi Round Robin */
    for(j=0; j<(max/t)+1; j++) {
        for(i=0; i<n; i++) {
            if(bu[i] != 0) {
                if(bu[i] <= t) { /* Jika sisa burst time kurang dari/sama dengan time slice */
                    tat[i] = temp + bu[i]; /* Catat completion time sementara di tat */
                    temp = temp + bu[i];
                    bu[i] = 0;
                } else { /* Jika sisa burst time lebih besar dari time slice */
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
            }
        }
    }
    
    for(i=0; i<n; i++) {
        wa[i] = tat[i] - ct[i]; /* Waiting time = Completion Time - Initial Burst Time */
        att += tat[i];
        awt += wa[i];
    }
    
    printf("\nThe Average Turnaround time is -- %f", att/n);
    printf("\nThe Average Waiting time is -- %f", awt/n);
    
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0; i<n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i+1, ct[i], wa[i], tat[i]);
    }
    
    return 0;
}


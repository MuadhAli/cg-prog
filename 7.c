#include<stdio.h>

// void rr(int n, int tq, int at[], int bt[]) {
//     int rt[10], wt[10], tat[10], rem = n, t = 0, i, flag = 0, twt = 0, ttat = 0;
//     // Initialize remaining time for each process
//     for (i = 0; i < n; i++) {
//         rt[i] = bt[i];
//     }
//     printf("\nProcess\t| Turnaround Time | Waiting Time\n");
//     while (rem != 0) {
//         for (i = 0; i < n; i++) {
//             if (rt[i] > 0) {
//                 if (rt[i] <= tq) {
//                     t += rt[i]; // Update time
//                     rt[i] = 0; // Process is complete
//                     flag = 1; // Flag to indicate completion
//                 }
//                 else {
//                     rt[i] -= tq; // Update remaining time
//                     t += tq; // Update time
//                 }
//                 if (rt[i] == 0 && flag == 1) {
//                     rem--; // Decrement remaining process count
//                     printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, t - at[i], t - at[i] - bt[i]);
//                     twt += t - at[i] - bt[i]; // Calculate total waiting time
//                     ttat += t - at[i]; // Calculate total turnaround time
//                     flag = 0; // Reset flag
//                 }
//             }
//         }
//     }

//     printf("\nAverage Waiting Time: %.2f\n", (float) twt / n);
//     printf("Averagae Turnaround Time: %.2f\n", (float) ttat / n);
// }


 void rr(int n,int tq,int at[],int bt[])
 {
  int rt[10], wt[10], tat[10], rem = n, t = 0, i, flag = 0, twt = 0, ttat = 0;
      for (i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
printf("Process|turnaround time |waiting time");

 while (rem != 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= tq) {
                    t += rt[i]; // Update time
                    rt[i] = 0; // Process is complete
                    flag = 1; // Flag to indicate completion
                }
                else {
                    rt[i] -= tq; // Update remaining time
                    t += tq; // Update time
                }
                if (rt[i] == 0 && flag == 1) {
                    rem--; // Decrement remaining process count
printf("p[%d]\t\t%d\t\t%d", i + 1, t - at[i], t - at[i] - bt[i]);
twt +=t-at[i]-bt[i];
ttat +=t-at[i];
flag=0;
}
}
}
}
printf("\nthe average waiting time is %.2f",(float)twt);
printf("\nthe average turnaround time is %.2f",(float)ttat);
}



void srtf(int n, int at[], int bt[]) {
    int rt[10], wt[10], tat[10], i, s, t = 0, rem = n, swt = 0, stat = 0;

    // Initialize remaining time for each process
    for (i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    rt[9] = 9999; // Set a high value for comparison

    printf("\nProcess\t| Turnaround Time | Waiting Time\n");
    while (rem != 0) {
        s = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] < rt[s] && rt[i] > 0) {
                s = i; // Find process with shortest remaining time
            }
        }
        rt[s]--; // Decrement remaining time for the selected process
        if (rt[s] == 0) {
            rem--; // Decrement remaining process count
            printf("P[%d]\t|\t%d\t|\t%d\n", s + 1, t + 1 - at[s], t + 1 - bt[s] - at[s]);
            swt += t + 1 - bt[s] - at[s]; // Calculate total waiting time
            stat += t + 1 - at[s]; // Calculate total turnaround time
        }
        t++; // Increment time
    }

    printf("\nAverage Waiting Time: %.2f\n", (float) swt / n);
    printf("Average Turnaround Time: %.2f\n", (float) stat / n);
}

int main() {
    int c, n, at[10], bt[10], tq;

    printf("Enter choice:\n1. Round Robin\n2. SRTF\n");
    scanf("%d", &c);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    switch (c) {
        case 1:
            printf("Enter Time Quantum: ");
            scanf("%d", &tq);
            rr(n, tq, at, bt);
            break;
        case 2:
            srtf(n, at, bt);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
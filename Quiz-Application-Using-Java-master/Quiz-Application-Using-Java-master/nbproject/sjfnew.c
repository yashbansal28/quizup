#include <stdio.h>
#define max 30

void main() {
    int i, j, n, t, p[max], bt[max], wt[max], tat[max], at[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter burst times of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival times of processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Sort processes based on arrival times using bubble sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival times
                t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;

                // Swap burst times (matching with arrival times)
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                // Swap process numbers (matching with arrival times)
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    printf("Process \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time \n");
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        for (j = 0; j < i; j++) {
            wt[i] = wt[i] + bt[j];
        }

        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i], bt[i], at[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("Average Waiting Time = %.2f\n", awt);
    printf("Average Turnaround Time = %.2f\n", atat);
}
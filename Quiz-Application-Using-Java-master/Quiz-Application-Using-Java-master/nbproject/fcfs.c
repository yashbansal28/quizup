#include <stdio.h>

// Function to perform bubble sort based on arrival times
void bubbleSort(int n, int bt[], int at[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival times
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times (matching with arrival times)
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, n, bt[30], at[30], wt[30], tat[30], temp[30];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Input burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Input arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Sort processes based on arrival times
    bubbleSort(n, bt, at);

    temp[0] = at[0];

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
#include <stdio.h>
int main(){

    int bt[100], tq, i, n, rembt[100], t = 0, wt[100], c = 0, p[100], tat[100];
    double total = 0, avgwt = 0;

    printf("Enter process number: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Input burst time for process P%d\n", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;

    }
    printf("Take input time quantum.\n");
    scanf("%d", &tq);

    for (i = 0; i < n;i++){
        rembt[i] = bt[i];
    }
    while (c!=n)
    {
        for (i = 0; i < n; i++){
            if(rembt[i]>tq){
                t += tq;
                rembt[i] -= tq;
            }else if(rembt[i]!=0){
                t += rembt[i];
                wt[i] = t - bt[i];
                tat[i] = t;
                total += wt[i];
                rembt[i] = 0;
                c++;

            }
        }
    }

    avgwt = total / n;
    printf("Process\t\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++){
        total == bt[i];
        printf("P[%d]\t\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    double avgtt = total / n;
    printf("Average waiting time: %f\n", avgwt);
    printf("Average turnaround time: %f\n", avgtt);
    return 0;
}

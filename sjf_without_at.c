#include <stdio.h>
int main()
{
    int i, n, j, temp;
    int bt[100], wt[100], tat[100], p[100];
    float awt = 0, atat = 0;
    printf("Shortest Job First Scheduling Non-Primitive(Simultaneous Arrival)\n");
    printf("Enter the No. of processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        //   printf("Enter the arrival time of %d process :\n",i+1);
        // scanf("%d",&at[i]);
        printf("Enter the burst time of %d process : ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    /*Sorting According to Burst Time*/
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    /*waiting time & turnaround time calculation of every process*/ wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        awt += wt[i];
        tat[i] = tat[i - 1] + bt[i];
        atat += tat[i];
    }
    atat += tat[0];
    atat /= n;
    awt /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t%8d\t%8d\t%8d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %0.3f\nAverage Turn Around Time:%0.3f", awt, atat);
    return 0;
}
// 6
// 9
// 4
// 6
// 2
// 5
// 3
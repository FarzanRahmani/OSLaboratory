#include <stdio.h>
struct process
{
    int pid, st, wt, tt;
};

int main()
{
    int processes_num;
    printf("what is number of processes? \n");
    scanf("%d", &processes_num);

    struct process processes[processes_num];

    for (int i = 0; i < processes_num; i++)
    {
        int service_time;
        printf("what is service time of process with pid = %d\n", i + 1);
        scanf("%d", &service_time);
        processes[i].st = service_time;
        processes[i].pid = i + 1;
    }

    int i, j;
    struct process swap_temp;
    // sorting
    for (i = 0; i < processes_num - 1; i++)
    {
        for (j = 0; j < processes_num - i - 1; j++)
        {
            if (processes[j].st > processes[j + 1].st)
            {
                swap_temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = swap_temp;
            }
        }
    }

    int total_waiting = 0;
    for (int i = 0; i < processes_num; i++)
    {
        if (i == 0)
            processes[i].wt = 0;
        else
            processes[i].wt = processes[i - 1].tt;
        total_waiting += processes[i].wt;
        processes[i].tt = processes[i].wt + processes[i].st;
        printf("process with pid:%d wait time:%d, service time:%d, total time: %d\n", i, processes[i].wt, processes[i].st, processes[i].tt);
    }
    double avg_wtime = (double) total_waiting / (double) processes_num;
    printf("avg wtime=%f\n", avg_wtime);

    return 0;
}

#include <stdio.h>
struct process
{
    int pid, st, wt, tt, finished;
};

int main()
{
    int quantum_time = 0;
    int processes_num = 0;
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
        processes[i].tt += service_time;
        processes[i].wt = 0;
    }

    printf("what is quantum time? \n");
    scanf("%d", &quantum_time);

    int total_waiting = 0;
    int finished_processes = 0;
    int i = 0;
    while (finished_processes < processes_num)
    {
        if (processes[i].st > 0)
        {
            if (processes[i].st > quantum_time)
            {
                for (int j = 0; j < processes_num; j++)
                {
                    if (processes[j].finished != 1 && j != i)
                        processes[j].wt += quantum_time;
                }
                
                processes[i].st -= quantum_time;
                printf("process %d has been run for %d\n", processes[i].pid, quantum_time);
            }
            else
            {
                for (int j = 0; j < processes_num; j++)
                {
                    if (j != i && processes[j].finished != 1)
                        processes[j].wt += processes[i].st;
                }
                
                processes[i].st = 0;
                printf("process %d has been run for %d\n", processes[i].pid, quantum_time);
                processes[i].finished = 1;
                finished_processes++;
            }
        }
        i = (i + 1) % processes_num;
    }
    
    for (int i = 0; i < processes_num; i++)
    {
        printf("process with pid %d should wait %d seconds\n", i + 1, processes[i].wt);
        total_waiting += processes[i].wt;
    }

    double avg_wtime = (double) total_waiting / (double) processes_num;
    printf("avg wtime=%f\n", avg_wtime);

    return 0;
}

#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
};
void priorityScheduling(struct Process proc[], int n) {
    int time = 0, completed = 0, minPriority, minIndex;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    while (completed < n) {
        minPriority = INT_MAX;
        minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrivalTime <= time && proc[i].remainingTime > 0 && proc[i].priority < minPriority) {
                minPriority = proc[i].priority;
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            time++;
            continue;
        }
        proc[minIndex].remainingTime--;
        time++;
        if (proc[minIndex].remainingTime == 0) {
            completed++;
            proc[minIndex].completionTime = time;
            proc[minIndex].turnaroundTime = proc[minIndex].completionTime - proc[minIndex].arrivalTime;
            proc[minIndex].waitingTime = proc[minIndex].turnaroundTime - proc[minIndex].burstTime;
            totalTurnaroundTime += proc[minIndex].turnaroundTime;
            totalWaitingTime += proc[minIndex].waitingTime;
        }
    }
    printf("\nPriority Scheduling (Preemptive):\n");
    printf("PID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].priority, proc[i].completionTime, proc[i].turnaroundTime, proc[i].waitingTime);
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}

void roundRobin(struct Process proc[], int n, int quantum) {
    int time = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0 && proc[i].arrivalTime <= time) {
                if (proc[i].remainingTime <= quantum) {
                    time += proc[i].remainingTime;
                    proc[i].remainingTime = 0;
                    completed++;
                    proc[i].completionTime = time;
                    proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
                    proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
                    totalTurnaroundTime += proc[i].turnaroundTime;
                    totalWaitingTime += proc[i].waitingTime;
                } else {
                    time += quantum;
                    proc[i].remainingTime -= quantum;
                }
            }
        }
    }
    printf("\nRound Robin (Time Quantum = %d):\n", quantum);
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].arrivalTime, proc[i].burstTime, proc[i].completionTime, proc[i].turnaroundTime, proc[i].waitingTime);
    }
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}
int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for process P%d (Arrival Time, Burst Time, Priority): ", i + 1);
        scanf("%d %d %d", &proc[i].arrivalTime, &proc[i].burstTime, &proc[i].priority);
        proc[i].pid = i + 1;
        proc[i].remainingTime = proc[i].burstTime;
    }
    priorityScheduling(proc, n);
    for (int i = 0; i < n; i++) {
        proc[i].remainingTime = proc[i].burstTime;
    }
    printf("\nEnter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    roundRobin(proc, n, quantum);
    return 0;
}

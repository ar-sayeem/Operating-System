#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void calculateNeedMatrix(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int alloc[MAX_PROCESSES][MAX_RESOURCES], int numProcesses, int numResources) {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool canGrantRequest(int need[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int process, int numResources) {
    for (int i = 0; i < numResources; i++) {
        if (need[process][i] > available[i]) {
            return false;
        }
    }
    return true;
}

bool isSafeState(int alloc[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int numProcesses, int numResources, int safeSequence[MAX_PROCESSES]) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int index = 0;
    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }
    for (int count = 0; count < numProcesses; count++) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i] && canGrantRequest(need, work, i, numResources)) {
                for (int j = 0; j < numResources; j++) {
                    work[j] += alloc[i][j];
                }
                safeSequence[index++] = i;
                finish[i] = true;
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    int numProcesses, numResources;
    int alloc[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int safeSequence[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Available Resources:\n");
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &available[i]);
    }

    calculateNeedMatrix(need, max, alloc, numProcesses, numResources);
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    if (isSafeState(alloc, need, available, numProcesses, numResources, safeSequence)) {
        printf("\nSystem is in a safe state. Safe sequence is: ");
        for (int i = 0; i < numProcesses; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is not in a safe state.\n");
    }

    return 0;
}

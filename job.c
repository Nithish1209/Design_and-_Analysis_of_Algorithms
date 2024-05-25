#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    char id;
    int dead;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return temp2->profit - temp1->profit;
}

int min(int num1, int num2) {
    return num1 > num2 ? num2 : num1;
}

void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);

    int result[n];
    bool slot[n];
    
    int i, j;
    for (i = 0; i < n; i++) {
        slot[i] = false;
    }

    for (i = 0; i < n; i++) {
        int deadline = min(n, arr[i].dead);
        for (j = deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    printf("Maximum profit job sequence:\n");
    for (i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", arr[result[i]].id);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job arr[n];
    
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter details for job %d:\n", i + 1);
        printf("  Job ID: ");
        scanf(" %c", &arr[i].id);
        printf("  Deadline: ");
        scanf("%d", &arr[i].dead);
        printf("  Profit: ");
        scanf("%d", &arr[i].profit);
    }

    printJobScheduling(arr, n);

    return 0;
}


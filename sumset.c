#include <stdio.h>

void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    int i;
    for (i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}


void findSubsets(int set[], int subset[], int setSize, int subsetSize, int index, int targetSum) {
    int sum = 0;

    int i;
    for (i = 0; i < subsetSize; i++) {
        sum += subset[i];
    }

    
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
    }

    
    if (index >= setSize) {
        return;
    }

    
    subset[subsetSize] = set[index];
    findSubsets(set, subset, setSize, subsetSize + 1, index + 1, targetSum);

    
    findSubsets(set, subset, setSize, subsetSize, index + 1, targetSum);
}

int main() {
    
    int set[] = {1, 2, 3, 4, 5};
    int setSize = sizeof(set) / sizeof(set[0]);

    
    int subset[setSize];


    int targetSum = 6;

    printf("Subsets with sum %d are:\n", targetSum);


    findSubsets(set, subset, setSize, 0, 0, targetSum);

    return 0;
}


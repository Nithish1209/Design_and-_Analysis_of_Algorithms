#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    int n;
    int i;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n];
    int values[n];

    printf("Enter the weights of the items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int max_value = knapsack(capacity, weights, values, n);

    printf("Maximum value in the knapsack: %d\n", max_value);

    return 0;
}


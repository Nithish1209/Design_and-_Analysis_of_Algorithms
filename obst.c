#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    int k;
    for (k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int optimalCost(int keys[], int freq[], int n) {
    int cost[n][n];
    int i;

    // Initialize the cost table
    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    int length, j, r;

    // Fill the cost table for all subarray lengths
    for (length = 2; length <= n; length++) {
        for (i = 0; i <= n - length; i++) {
            j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int c = leftCost + rightCost + sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];
    int freq[n];

    int i;

    printf("Enter the keys: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int optimal_cost = optimalCost(keys, freq, n);

    printf("The optimal cost for the given keys is: %d\n", optimal_cost);

    return 0;
}


#include<stdio.h>

int main() {
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n]; 
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array elements: ");
    for(i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }

    int target;
    printf("\nEnter the target value: ");
    scanf("%d", &target);

    int s = 0, e = n - 1;
    int found = 0;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (a[mid] == target) {
            printf("Element found at index: %d\n", mid);
            found = 1;  
            break;  
        } else if (a[mid] < target) {
            s = mid + 1;  
        } else {
            e = mid - 1;  
        }
    }

    if (!found) {
        printf("Element not found in the array\n");
    }

    return 0;
}


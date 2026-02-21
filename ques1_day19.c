#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void closestToZero(int* arr, int n) {
    if(n < 2) {
        printf("Array must have at least two elements\n");
        return;
    }

    // Sort the array
    qsort(arr, n, sizeof(int), cmp);

    int left = 0;
    int right = n - 1;

    int min_sum = INT_MAX;
    int best_l = left, best_r = right;

    while(left < right) {
        int sum = arr[left] + arr[right];

        // Update closest sum
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            best_l = left;
            best_r = right;
        }

        // Move pointers
        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("\nTwo elements closest to zero are: %d and %d\n",
           arr[best_l], arr[best_r]);
    printf("Closest sum to zero = %d\n", min_sum);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Need at least two numbers!\n");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    closestToZero(arr, n);

    free(arr);
    return 0;
}

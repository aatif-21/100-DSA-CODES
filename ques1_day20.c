#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (long long)
int cmp(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

long long countZeroSumSubarrays(int* arr, int n) {
    // Prefix sum array
    long long* prefix = (long long*)malloc(sizeof(long long) * (n + 1));

    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Sort prefix sums
    qsort(prefix, n + 1, sizeof(long long), cmp);

    long long count = 0;
    long long freq = 1;

    // Count equal prefix sums
    for(int i = 1; i <= n; i++) {
        if(prefix[i] == prefix[i - 1]) {
            freq++;
        } else {
            // nC2 = freq * (freq - 1) / 2
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    // Last group
    count += (freq * (freq - 1)) / 2;

    free(prefix);
    return count;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = countZeroSumSubarrays(arr, n);
    printf("\nNumber of subarrays with sum 0 = %lld\n", result);

    free(arr);
    return 0;
}

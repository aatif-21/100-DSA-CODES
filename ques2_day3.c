//You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

#include <stdio.h>

int missingNumber(int arr[], int n) {
    int xorAll = 0;

    for (int i = 1; i <= n; i++)
        xorAll ^= i;

    for (int i = 0; i < n - 1; i++)
        xorAll ^= arr[i];

    return xorAll;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", missingNumber(arr, n));
    return 0;
}

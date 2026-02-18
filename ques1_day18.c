#include <stdio.h>

// Function to reverse part of the array
void reverse(int* arr, int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// Function to rotate array to the right by k positions
void rotate(int* arr, int n, int k) {
    if (n == 0) return;

    // Handle cases where k > n
    k = k % n;

    // Step 1: Reverse whole array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
}

int main() {
    int n, k;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k (positions to rotate right): ");
    scanf("%d", &k);

    rotate(arr, n, k);

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

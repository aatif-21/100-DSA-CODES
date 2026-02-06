// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int unique_count = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[unique_count] = arr[i];
            unique_count++;
        }
    }
    
    printf("Unique elements in order: ");
    for (int i = 0; i < unique_count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
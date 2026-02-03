//Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>
int main() {

    int arr[100], n,k, comparisons = 0; 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &k);
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Key found at index %d after %d comparisons.\n", i, comparisons);
            return 0;
        }
    }
    printf("Key not found after %d comparisons.\n", comparisons);
    return 0;
}
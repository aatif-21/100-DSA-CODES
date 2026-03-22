#include <stdio.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Swap and continue heapifying
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Display array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int arr[] = {30, 10, 50, 20, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    display(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    display(arr, n);

    return 0;
}
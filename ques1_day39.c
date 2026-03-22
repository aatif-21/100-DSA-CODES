#include <stdio.h>
#define SIZE 100

int heap[SIZE];
int size = 0;

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into heap
void insert(int value)
{
    if (size == SIZE)
    {
        printf("Heap Overflow\n");
        return;
    }

    // Insert at end
    heap[size] = value;
    int i = size;
    size++;

    // Heapify up
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("%d inserted\n", value);
}

// Delete root (minimum element)
void deleteMin()
{
    if (size == 0)
    {
        printf("Heap Underflow\n");
        return;
    }

    printf("%d removed (min)\n", heap[0]);

    // Replace root with last element
    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    // Heapify down
    while (2 * i + 1 < size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if (right < size && heap[right] < heap[left])
        {
            smallest = right;
        }

        if (heap[i] <= heap[smallest])
        {
            break;
        }

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

// Display heap
void display()
{
    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main
int main()
{
    insert(30);
    insert(10);
    insert(50);
    insert(5);
    insert(20);

    display();

    deleteMin();
    display();

    return 0;
}
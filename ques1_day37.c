#include <stdio.h>
#define SIZE 100

int pq[SIZE];
int n = 0;

// Insert element
void enqueue(int value)
{
    if (n == SIZE)
    {
        printf("Queue Overflow\n");
        return;
    }

    pq[n++] = value;
    printf("%d inserted\n", value);
}

// Delete highest priority element (smallest value)
void dequeue()
{
    if (n == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    int minIndex = 0;

    // Find smallest element
    for (int i = 1; i < n; i++)
    {
        if (pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }

    printf("%d removed (highest priority)\n", pq[minIndex]);

    // Shift elements
    for (int i = minIndex; i < n - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    n--;
}

// Display queue
void display()
{
    if (n == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

// Main
int main()
{
    enqueue(30);
    enqueue(10);
    enqueue(50);
    enqueue(20);

    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Insert at front
void insertFront(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

// Insert at rear
void insertRear(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

// Delete from front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d removed from front\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete from rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d removed from rear\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

// Display deque
void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
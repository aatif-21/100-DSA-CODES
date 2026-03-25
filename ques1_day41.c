#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Define Queue structure
struct Queue
{
    struct Node *front, *rear;
};

// Function to create a new queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }

    // Add at the end
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation
int dequeue(struct Queue *q)
{
    // If queue is empty
    if (q->front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    // If queue becomes empty
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Display queue
void display(struct Queue *q)
{
    struct Node *temp = q->front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test
int main()
{
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    return 0;
}
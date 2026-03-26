#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Queue structure
struct Queue
{
    int arr[SIZE];
    int front, rear;
};

// Stack structure
struct Stack
{
    int arr[SIZE];
    int top;
};

// Queue functions
void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isQueueEmpty(struct Queue *q)
{
    return q->front == -1;
}

int isQueueFull(struct Queue *q)
{
    return q->rear == SIZE - 1;
}

void enqueue(struct Queue *q, int val)
{
    if (isQueueFull(q))
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = val;
}

int dequeue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

// Stack functions
void initStack(struct Stack *s)
{
    s->top = -1;
}

int isStackEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isStackFull(struct Stack *s)
{
    return s->top == SIZE - 1;
}

void push(struct Stack *s, int val)
{
    if (isStackFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(struct Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Reverse queue using stack
void reverseQueue(struct Queue *q)
{
    struct Stack s;
    initStack(&s);

    // Step 1: Queue → Stack
    while (!isQueueEmpty(q))
    {
        push(&s, dequeue(q));
    }

    // Step 2: Stack → Queue
    while (!isStackEmpty(&s))
    {
        enqueue(q, pop(&s));
    }
}

// Display queue
void display(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main
int main()
{
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Original Queue:\n");
    display(&q);

    reverseQueue(&q);

    printf("Reversed Queue:\n");
    display(&q);

    return 0;
}
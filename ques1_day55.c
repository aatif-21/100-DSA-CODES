#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Queue
{
    struct Node **arr;
    int front, rear, cap;
};

void initQueue(struct Queue *q, int cap)
{
    q->arr = (struct Node **)malloc(cap * sizeof(struct Node *));
    q->front = 0;
    q->rear = 0;
    q->cap = cap;
}

void enqueue(struct Queue *q, struct Node *n)
{
    if (q->rear == q->cap)
    {
        q->cap *= 2;
        q->arr = realloc(q->arr, q->cap * sizeof(struct Node *));
    }
    q->arr[q->rear++] = n;
}

struct Node *dequeue(struct Queue *q)
{
    if (q->front == q->rear)
        return NULL;
    return q->arr[q->front++];
}

int queueSize(struct Queue *q) { return q->rear - q->front; }

void rightSideView(struct Node *root)
{
    if (!root)
        return;

    struct Queue q;
    initQueue(&q, 64);
    enqueue(&q, root);

    printf("Right Side View:\n");

    while (queueSize(&q) > 0)
    {
        int levelSize = queueSize(&q); // number of nodes at current level

        for (int i = 0; i < levelSize; i++)
        {
            struct Node *node = dequeue(&q);

            // Last node in the level = rightmost visible node
            if (i == levelSize - 1)
                printf("%d ", node->data);

            if (node->left)
                enqueue(&q, node->left);
            if (node->right)
                enqueue(&q, node->right);
        }
    }

    printf("\n");
    free(q.arr);
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(6);

    rightSideView(root);
    return 0;
}
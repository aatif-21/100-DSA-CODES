#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Queue node for BFS (stores tree node + its horizontal distance)
struct QNode
{
    struct Node *node;
    int hd;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find min and max horizontal distance in the tree
void findMinMax(struct Node *root, int *minHD, int *maxHD, int hd)
{
    if (!root)
        return;
    if (hd < *minHD)
        *minHD = hd;
    if (hd > *maxHD)
        *maxHD = hd;
    findMinMax(root->left, minHD, maxHD, hd - 1);
    findMinMax(root->right, minHD, maxHD, hd + 1);
}

// BFS-based vertical order traversal
void verticalOrder(struct Node *root)
{
    if (!root)
        return;

    int minHD = 0, maxHD = 0;
    findMinMax(root, &minHD, &maxHD, 0);

    int cols = maxHD - minHD + 1;

    // Each column holds a dynamic list of values
    int **columns = (int **)malloc(cols * sizeof(int *));
    int *colSizes = (int *)calloc(cols, sizeof(int));
    int *colCap = (int *)malloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++)
    {
        colCap[i] = 8;
        columns[i] = (int *)malloc(colCap[i] * sizeof(int));
    }

    // BFS queue
    int qCap = 1024;
    struct QNode *queue = (struct QNode *)malloc(qCap * sizeof(struct QNode));
    int front = 0, rear = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear)
    {
        struct QNode curr = queue[front++];
        int col = curr.hd - minHD;

        // Append value to its column
        if (colSizes[col] == colCap[col])
        {
            colCap[col] *= 2;
            columns[col] = (int *)realloc(columns[col], colCap[col] * sizeof(int));
        }
        columns[col][colSizes[col]++] = curr.node->data;

        if (curr.node->left)
            queue[rear++] = (struct QNode){curr.node->left, curr.hd - 1};
        if (curr.node->right)
            queue[rear++] = (struct QNode){curr.node->right, curr.hd + 1};
    }

    // Print results
    printf("Vertical Order Traversal:\n");
    for (int i = 0; i < cols; i++)
    {
        printf("HD %2d: ", i + minHD);
        for (int j = 0; j < colSizes[i]; j++)
            printf("%d ", columns[i][j]);
        printf("\n");
    }

    // Cleanup
    for (int i = 0; i < cols; i++)
        free(columns[i]);
    free(columns);
    free(colSizes);
    free(colCap);
    free(queue);
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    verticalOrder(root);
    return 0;
}
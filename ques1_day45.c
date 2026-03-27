#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find height
int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main
int main()
{

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of tree: %d\n", height(root));

    return 0;
}
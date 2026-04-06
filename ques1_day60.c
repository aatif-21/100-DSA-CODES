#include <stdio.h>
#include <stdlib.h>

// Node structure
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Count total nodes
int countNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is complete
int isComplete(struct TreeNode *root, int index, int totalNodes)
{
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Min-Heap property
int isMinHeap(struct TreeNode *root)
{
    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Only left child
    if (root->right == NULL)
    {
        return (root->val <= root->left->val) &&
               isMinHeap(root->left);
    }

    // Both children
    if (root->val <= root->left->val &&
        root->val <= root->right->val)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

// Main check function
int checkMinHeap(struct TreeNode *root)
{
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        return 1;
    else
        return 0;
}

int main()
{

    struct TreeNode *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    if (checkMinHeap(root))
        printf("Tree is a Min-Heap\n");
    else
        printf("Tree is NOT a Min-Heap\n");

    return 0;
}
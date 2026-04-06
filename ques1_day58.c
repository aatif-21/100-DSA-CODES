#include <stdio.h>
#include <stdlib.h>

// Structure of node
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

// Find index of value in inorder array
int findIndex(int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree function
struct TreeNode *buildTree(int preorder[], int inorder[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;

    // Pick current root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode *root = newNode(rootVal);

    // If only one node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, start, end, rootVal);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Inorder traversal (to verify)
void inorderPrint(struct TreeNode *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    printf("%d ", root->val);
    inorderPrint(root->right);
}

// Main function
int main()
{
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};

    int n = 5;
    int preIndex = 0;

    struct TreeNode *root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder of constructed tree: ");
    inorderPrint(root);

    return 0;
}
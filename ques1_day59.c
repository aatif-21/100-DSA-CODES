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

// Find index in inorder
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
struct TreeNode *buildTree(int inorder[], int postorder[], int start, int end, int *postIndex)
{
    if (start > end)
        return NULL;

    // Pick root from postorder
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode *root = newNode(rootVal);

    // If single node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = findIndex(inorder, start, end, rootVal);

    // IMPORTANT: build right subtree first
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Inorder print (verification)
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
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    int n = 5;
    int postIndex = n - 1;

    struct TreeNode *root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Inorder of constructed tree: ");
    inorderPrint(root);

    return 0;
}
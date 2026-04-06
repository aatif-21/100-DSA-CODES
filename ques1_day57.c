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

// Function to convert tree to mirror
void mirror(struct TreeNode *root)
{
    if (root == NULL)
        return;

    // Swap left and right
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively apply to subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal (to display tree)
void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main()
{
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder of Original Tree: ");
    inorder(root);

    // Convert to mirror
    mirror(root);

    printf("\nInorder of Mirror Tree: ");
    inorder(root);

    return 0;
}
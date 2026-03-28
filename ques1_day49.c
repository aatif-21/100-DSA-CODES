#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper to create a new node
struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ✅ BST Insert
struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val); // Go Left
    else if (val > root->val)
        root->right = insert(root->right, val); // Go Right

    return root;
}

// Inorder Traversal to verify BST (Left → Root → Right)
void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{

    struct TreeNode *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Inorder Traversal (Sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}

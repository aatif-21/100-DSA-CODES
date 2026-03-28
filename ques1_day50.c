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

// BST Insert (to build tree)
struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

// ✅ BST Search (Recursive)
struct TreeNode *searchRecursive(struct TreeNode *root, int key)
{
    if (root == NULL)
        return NULL; // Not Found
    if (root->val == key)
        return root; // Found

    if (key < root->val)
        return searchRecursive(root->left, key); // Go Left
    else
        return searchRecursive(root->right, key); // Go Right
}

// ✅ BST Search (Iterative)
struct TreeNode *searchIterative(struct TreeNode *root, int key)
{
    while (root != NULL)
    {
        if (root->val == key)
            return root; // Found
        else if (key < root->val)
            root = root->left; // Go Left
        else
            root = root->right; // Go Right
    }
    return NULL; // Not Found
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

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    // Recursive Search
    struct TreeNode *resRec = searchRecursive(root, key);
    if (resRec)
        printf("Recursive  → Found: %d\n", resRec->val);
    else
        printf("Recursive  → Not Found\n");

    // Iterative Search
    struct TreeNode *resItr = searchIterative(root, key);
    if (resItr)
        printf("Iterative  → Found: %d\n", resItr->val);
    else
        printf("Iterative  → Not Found\n");

    return 0;
}

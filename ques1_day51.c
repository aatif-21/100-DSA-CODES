#include <stdio.h>
#include <stdlib.h>

// ── Node definition ───────────────────────────────────────────────
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// ── Helper: create a new node ─────────────────────────────────────
TreeNode *newNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ── Helper: insert into BST ───────────────────────────────────────
TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ── Helper: find a node by value ──────────────────────────────────
TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (val == root->val)
        return root;
    if (val < root->val)
        return findNode(root->left, val);
    return findNode(root->right, val);
}

// ═════════════════════════════════════════════════════════════════
// APPROACH 1 — Recursive
//
// BST property:
//   • Both p and q are in the LEFT  subtree  → LCA is on the left
//   • Both p and q are in the RIGHT subtree  → LCA is on the right
//   • They split here (or one equals root)   → root IS the LCA
// ═════════════════════════════════════════════════════════════════
TreeNode *lcaRecursive(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;

    if (p->val < root->val && q->val < root->val)
        return lcaRecursive(root->left, p, q); // both in left subtree

    if (p->val > root->val && q->val > root->val)
        return lcaRecursive(root->right, p, q); // both in right subtree

    return root; // split point → this node is the LCA
}

// ═════════════════════════════════════════════════════════════════
// APPROACH 2 — Iterative  (O(1) space — no call stack)
// ═════════════════════════════════════════════════════════════════
TreeNode *lcaIterative(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *cur = root;

    while (cur)
    {
        if (p->val < cur->val && q->val < cur->val)
            cur = cur->left; // both smaller → go left

        else if (p->val > cur->val && q->val > cur->val)
            cur = cur->right; // both larger  → go right

        else
            return cur; // split point → LCA found
    }
    return NULL;
}

// ── Utility: free the whole tree ─────────────────────────────────
void freeTree(TreeNode *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void)
{
    // Build BST
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    int n = sizeof(values) / sizeof(values[0]);

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    // Test cases: {p, q, expected_LCA}
    int tests[][3] = {
        {2, 8, 6},
        {2, 4, 2},
        {3, 5, 4},
        {7, 9, 8},
        {0, 5, 2},
    };
    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("%-6s %-6s %-10s %-10s %-6s\n",
           "p", "q", "Recursive", "Iterative", "Expected");
    printf("----------------------------------------------\n");

    for (int i = 0; i < numTests; i++)
    {
        TreeNode *p = findNode(root, tests[i][0]);
        TreeNode *q = findNode(root, tests[i][1]);

        TreeNode *r1 = lcaRecursive(root, p, q);
        TreeNode *r2 = lcaIterative(root, p, q);

        printf("%-6d %-6d %-10d %-10d %-6d\n",
               p->val, q->val,
               r1 ? r1->val : -1,
               r2 ? r2->val : -1,
               tests[i][2]);
    }

    freeTree(root);
    return 0;
}

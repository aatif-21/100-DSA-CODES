#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    node->left = node->right = NULL;
    return node;
}

TreeNode *lcaRecursive(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base: empty node, or we found p or q
    if (!root || root == p || root == q)
        return root;

    TreeNode *left = lcaRecursive(root->left, p, q);
    TreeNode *right = lcaRecursive(root->right, p, q);

    // p and q are on opposite sides → current node is LCA
    if (left && right)
        return root;

    // Both found in same subtree, or neither found
    return left ? left : right;
}

#define MAP_SIZE 1024

typedef struct Entry
{
    TreeNode *key;
    TreeNode *val;
    struct Entry *next;
} Entry;

Entry *parentMap[MAP_SIZE];

void mapClear(void)
{
    for (int i = 0; i < MAP_SIZE; i++)
        parentMap[i] = NULL;
}

int mapHash(TreeNode *key)
{
    return (int)((unsigned long)key % MAP_SIZE);
}

void mapPut(TreeNode *key, TreeNode *val)
{
    int h = mapHash(key);
    Entry *e = (Entry *)malloc(sizeof(Entry));
    e->key = key;
    e->val = val;
    e->next = parentMap[h];
    parentMap[h] = e;
}

TreeNode *mapGet(TreeNode *key)
{
    int h = mapHash(key);
    for (Entry *e = parentMap[h]; e; e = e->next)
        if (e->key == key)
            return e->val;
    return NULL;
}

void mapFreeAll(void)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        Entry *e = parentMap[i];
        while (e)
        {
            Entry *tmp = e->next;
            free(e);
            e = tmp;
        }
        parentMap[i] = NULL;
    }
}

// --- Tiny hash set: node pointer ---------------------------------
typedef struct SetEntry
{
    TreeNode *key;
    struct SetEntry *next;
} SetEntry;

SetEntry *ancestorSet[MAP_SIZE];

void setClear(void)
{
    for (int i = 0; i < MAP_SIZE; i++)
        ancestorSet[i] = NULL;
}

void setAdd(TreeNode *key)
{
    int h = mapHash(key);
    SetEntry *e = (SetEntry *)malloc(sizeof(SetEntry));
    e->key = key;
    e->next = ancestorSet[h];
    ancestorSet[h] = e;
}

bool setContains(TreeNode *key)
{
    int h = mapHash(key);
    for (SetEntry *e = ancestorSet[h]; e; e = e->next)
        if (e->key == key)
            return true;
    return false;
}

void setFreeAll(void)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        SetEntry *e = ancestorSet[i];
        while (e)
        {
            SetEntry *tmp = e->next;
            free(e);
            e = tmp;
        }
        ancestorSet[i] = NULL;
    }
}

// --- Iterative LCA -----------------------------------------------
TreeNode *lcaIterative(TreeNode *root, TreeNode *p, TreeNode *q)
{
    mapClear();
    setClear();

    // 1. BFS to fill parent map (root's parent = NULL)
    TreeNode *queue[1024];
    int head = 0, tail = 0;
    queue[tail++] = root;
    mapPut(root, NULL);

    // Stop as soon as we've seen both p and q
    while (head < tail)
    {
        TreeNode *node = queue[head++];
        if (node->left)
        {
            mapPut(node->left, node);
            queue[tail++] = node->left;
        }
        if (node->right)
        {
            mapPut(node->right, node);
            queue[tail++] = node->right;
        }
    }

    // 2. Collect all ancestors of p (including p itself)
    TreeNode *cur = p;
    while (cur)
    {
        setAdd(cur);
        cur = mapGet(cur); // walk up to parent
    }

    // 3. Walk up from q; first node in p's ancestor set = LCA
    cur = q;
    while (cur)
    {
        if (setContains(cur))
        {
            mapFreeAll();
            setFreeAll();
            return cur;
        }
        cur = mapGet(cur);
    }

    mapFreeAll();
    setFreeAll();
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
    // Build tree manually
    TreeNode *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    // Grab node pointers for testing
    TreeNode *n5 = root->left;
    TreeNode *n1 = root->right;
    TreeNode *n6 = root->left->left;
    TreeNode *n2 = root->left->right;
    TreeNode *n0 = root->right->left;
    TreeNode *n4 = root->left->right->right;

    // Test cases: {p, q, expected}
    struct
    {
        TreeNode *p, *q;
        int expected;
    } tests[] = {
        {n5, n1, 3},
        {n5, n4, 5},
        {n6, n4, 5},
        {n0, n4, 3},
        {n2, n6, 5},
    };
    int numTests = sizeof(tests) / sizeof(tests[0]);

    printf("%-6s %-6s %-10s %-10s %-8s\n",
           "p", "q", "Recursive", "Iterative", "Expected");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numTests; i++)
    {
        TreeNode *r1 = lcaRecursive(root, tests[i].p, tests[i].q);
        TreeNode *r2 = lcaIterative(root, tests[i].p, tests[i].q);
        printf("%-6d %-6d %-10d %-10d %-8d\n",
               tests[i].p->val, tests[i].q->val,
               r1 ? r1->val : -1,
               r2 ? r2->val : -1,
               tests[i].expected);
    }

    freeTree(root);
    return 0;
}
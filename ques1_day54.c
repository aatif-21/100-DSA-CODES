#include <stdio.h>
#include <stdlib.h>

// ── Tree Node ────────────────────────────────────────────────────────────────
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// ── Stack (for zigzag) ───────────────────────────────────────────────────────
struct Stack
{
    struct Node **arr;
    int top, cap;
};

void initStack(struct Stack *s, int cap)
{
    s->arr = (struct Node **)malloc(cap * sizeof(struct Node *));
    s->top = -1;
    s->cap = cap;
}

void push(struct Stack *s, struct Node *n)
{
    if (s->top + 1 == s->cap)
    {
        s->cap *= 2;
        s->arr = realloc(s->arr, s->cap * sizeof(struct Node *));
    }
    s->arr[++(s->top)] = n;
}

struct Node *pop(struct Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->arr[(s->top)--];
}

int isEmpty(struct Stack *s) { return s->top == -1; }

// ── Zigzag Traversal ─────────────────────────────────────────────────────────
void zigzagTraversal(struct Node *root)
{
    if (!root)
        return;

    struct Stack curr, next;
    initStack(&curr, 64);
    initStack(&next, 64);

    push(&curr, root);
    int leftToRight = 1; // direction flag
    int level = 0;

    while (!isEmpty(&curr))
    {
        struct Node *node = pop(&curr);
        printf("%d ", node->data);

        if (leftToRight)
        {
            // Push left before right so right is popped first next level
            if (node->left)
                push(&next, node->left);
            if (node->right)
                push(&next, node->right);
        }
        else
        {
            // Push right before left so left is popped first next level
            if (node->right)
                push(&next, node->right);
            if (node->left)
                push(&next, node->left);
        }

        if (isEmpty(&curr))
        {
            printf("\n");
            leftToRight = !leftToRight; // flip direction
            level++;

            // Swap curr <-> next
            struct Stack tmp = curr;
            curr = next;
            next = tmp;
        }
    }

    free(curr.arr);
    free(next.arr);
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
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    printf("Zigzag Level Order Traversal:\n");
    printf("Level 0 (L→R): ");
    zigzagTraversal(root);

    return 0;
}
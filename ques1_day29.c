#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at end
struct ListNode* appendNode(struct ListNode* head, int value) {
    struct ListNode* newNode = createNode(value);
    
    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to rotate list right by k places
struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = 1;
    struct ListNode* tail = head;

    // Find length and last node
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0)
        return head;

    // Make circular
    tail->next = head;

    int stepsToNewTail = length - k;
    struct ListNode* newTail = head;

    for (int i = 1; i < stepsToNewTail; i++)
        newTail = newTail->next;

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct ListNode* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = appendNode(head, value);
    }

    printf("Enter k (rotation count): ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List: ");
    printList(head);

    freeList(head);

    return 0;
}
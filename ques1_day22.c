#include <stdio.h>
#include <stdlib.h>

// Definition of singly linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to count nodes
int countNodes(struct ListNode* head) {
    int count = 0;
    struct ListNode* curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
void insertEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct ListNode* head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 40 -> NULL
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Linked List: ");
    printList(head);

    int total = countNodes(head);
    printf("Total nodes = %d\n", total);

    return 0;
}
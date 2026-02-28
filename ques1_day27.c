#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move longer list ahead
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;   // Intersection found (same memory address)
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function (demo)
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // List 1: 1 -> 2 -> 3 -> 4 -> 5
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);
    insertEnd(&head1, 4);
    insertEnd(&head1, 5);

    // List 2: 9 -> 10
    insertEnd(&head2, 9);
    insertEnd(&head2, 10);

    // Create intersection at node with value 3
    struct Node* temp = head1;
    while (temp->data != 3)
        temp = temp->next;

    // Connect list2 to list1's node (intersection)
    struct Node* t2 = head2;
    while (t2->next != NULL)
        t2 = t2->next;
    t2->next = temp;

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node* intersect = getIntersection(head1, head2);

    if (intersect != NULL)
        printf("\nIntersection Point Data = %d\n", intersect->data);
    else
        printf("\nNo Intersection Found\n");

    return 0;
}
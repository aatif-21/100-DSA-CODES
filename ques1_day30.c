#include <stdio.h>
#include <stdlib.h>

// Define structure for polynomial term
struct Node {
    int coeff;
    int power;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Insert node in descending order of power
struct Node* insertTerm(struct Node* head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);

    if (head == NULL || power > head->power) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->power > power) {
        temp = temp->next;
    }

    // If same power exists, add coefficients
    if (temp->next != NULL && temp->next->power == power) {
        temp->next->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Display polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            result = insertTerm(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) {
            result = insertTerm(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else {
            result = insertTerm(result,
                                poly1->coeff + poly2->coeff,
                                poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // First Polynomial: 5x^2 + 4x^1 + 2
    poly1 = insertTerm(poly1, 5, 2);
    poly1 = insertTerm(poly1, 4, 1);
    poly1 = insertTerm(poly1, 2, 0);

    // Second Polynomial: 5x^1 + 5
    poly2 = insertTerm(poly2, 5, 1);
    poly2 = insertTerm(poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result (Addition): ");
    display(result);

    return 0;
}
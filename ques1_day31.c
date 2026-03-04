#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size = 5;     // Stack size (fixed)
int stack[5];     // Array declaration

// Push operation
void push(int element) {
    if (top == size - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed into stack\n", element);
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
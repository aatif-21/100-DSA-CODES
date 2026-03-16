#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    int i = 0;
    
    while (exp[i] != '\0') {
        
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char to int
        }
        else {
            int val2 = pop();
            int val1 = pop();
            
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    
    return pop();
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
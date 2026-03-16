#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int main(){
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++){
        
        // operand
        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }
        
        // left parenthesis
        else if(infix[i] == '('){
            push(infix[i]);
        }
        
        // right parenthesis
        else if(infix[i] == ')'){
            while(stack[top] != '('){
                postfix[j++] = pop();
            }
            pop(); 
        }
        
        // operator
        else{
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
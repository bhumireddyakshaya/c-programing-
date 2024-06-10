#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

char pop() {
    char item;

    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol, temp;

    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (symbol == '(') {
            push(symbol);
        } else if (isalnum(symbol)) {
            postfix[j] = symbol;
            j++;
        } else if (symbol == ')') {
            temp = pop();
            while (temp != '(') {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
        } else {
            while (precedence(stack[top]) >= precedence(symbol)) {
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            push(symbol);
        }
        i++;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


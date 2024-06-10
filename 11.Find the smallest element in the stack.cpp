#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
    int min;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
    stack->min = INT_MAX;
}

void push(Stack *stack, int val) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }

    if (val < stack->min) {
        stack->items[++stack->top] = 2 * val - stack->min;
        stack->min = val;
    } else {
        stack->items[++stack->top] = val;
    }
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int top = stack->items[stack->top--];
    int popped;

    if (top < stack->min) {
        popped = stack->min;
        stack->min = 2 * stack->min - top;
    } else {
        popped = top;
    }

    return popped;
}

int getMin(Stack *stack) {
    return stack->min;
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 2);
    push(&stack, 1);

    printf("Minimum element in the stack: %d\n", getMin(&stack));

    pop(&stack);
    pop(&stack);

    printf("Minimum element in the stack after popping: %d\n", getMin(&stack));

    return 0;
}


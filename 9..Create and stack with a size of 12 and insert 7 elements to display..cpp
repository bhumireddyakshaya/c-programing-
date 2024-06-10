#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 12

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full, cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    stack.top = -1;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);

    display(&stack);

    return 0;
}


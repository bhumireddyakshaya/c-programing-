#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}
void displayReverse(struct Node* head) {
    struct Node* tail = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (tail->next != NULL) {
        tail = tail->next;
    }
    printf("List in reverse order: ");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    displayReverse(head);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
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
}
struct Node* combineLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }

    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head2;
    return head1;
}
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    appendNode(&head1, 3);
    appendNode(&head2, 4);
    appendNode(&head2, 5);
    appendNode(&head2, 6);

    printf("First list:\n");
    displayList(head1);

    printf("Second list:\n");
    displayList(head2);
    struct Node* combinedHead = combineLists(head1, head2);

    printf("Combined list:\n");
    displayList(combinedHead);

    return 0;
}


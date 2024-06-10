#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void updateItem(struct Node* head, int position, int newData) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (count == position) {
            temp->data = newData;
            break;
        }
        count++;
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    updateItem(head, 1, 5); // Update the item at position 1 to have a new value of 5

    return 0;
}


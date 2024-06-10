#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void splitDoublyLinkedList(struct Node* head, struct Node** firstHalf, struct Node** secondHalf) {
    struct Node* fast = head;
    struct Node* slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next->prev = NULL;
    slow->next = NULL;
}

int main() {
    struct Node* head = NULL;
    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;
    splitDoublyLinkedList(head, &firstHalf, &secondHalf);

    return 0;
}


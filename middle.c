#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(struct Node **start, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *start;
    *start = newNode;
}

int middle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head1 = NULL;
    insertAtFirst(&head1, 1);
    insertAtFirst(&head1, 3);
    insertAtFirst(&head1, 5);
    insertAtFirst(&head1, 2);
    insertAtFirst(&head1, 7);
    insertAtFirst(&head1, 9);
    print(head1);
    printf("%d\n", middle(head1));

    Node *head2 = NULL;
    insertAtFirst(&head2, 3);
    insertAtFirst(&head2, 5);
    insertAtFirst(&head2, 2);
    insertAtFirst(&head2, 7);
    insertAtFirst(&head2, 9);
    print(head2);
    printf("%d\n", middle(head2));

    return 0;
}


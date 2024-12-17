#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *createNode (int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtFirst(struct Node **start, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next=*start;
    *start=newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position == 0)
    {
        insertAtFirst(head, data);
        return;
    }
    struct Node *temp= *head;
    for (int i=0; temp!=NULL && i<position-2; i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Position out of range \n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next=newNode;
}

void print(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head=NULL;
    printf(head);
    printf(&head);
/*
    insertAtFirst(&head, 1);
    printf("Linked List after inserting node with value 1 at the beginning: ");
    print(head);
    insertAtFirst(&head, 4);
    printf("Linked List after inserting node with value 4 at the beginning: ");
    print(head);
    insertAtEnd(&head, 10);
    printf("Linked List after inserting node with value 10 at the end: ");
    print(head);
    insertAtEnd(&head, 40);
    printf("Linked List after inserting node with value 40  at the end: ");
    print(head);
    insertAtPosition(&head, 20, 2);
    printf("Linked List after inserting node with value 20 at the second position: ");
    print(head);
    return 0;
*/
}

#include <stdio.h>
#include <stdlib.h>

// node creation
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// insert node at the front
    void insertFront(struct Node** head, int data) {
      // allocate memory for newNode
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

      // assign data to newNode
      newNode->data = data;

      // make newNode as a head
      newNode->next = (*head);

      // assign null to prev
      newNode->prev = NULL;

      // previous of head (now head is the second node) is newNode
      if ((*head) != NULL)
        (*head)->prev = newNode;

      // head points to newNode
      (*head) = newNode;
    }

// insert a node after a specific node
    void insertAfter(struct Node* prev_node, int data) {
      // check if previous node is null
      if (prev_node == NULL) {
        printf("previous node cannot be null");
        return;
      }

      // allocate memory for newNode
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

      // assign data to newNode
      newNode->data = data;

      // set next of newNode to next of previous node
      newNode->next = prev_node->next;

      // set next of previous node to newNode
      prev_node->next = newNode;

      // set previous of newNode to the previous node
      newNode->prev = prev_node;

      // set previous of newNode's next to newNode
      if (newNode->next != NULL)
        newNode->next->prev = newNode;
    }

    // insert a newNode at the end of the list
    void insertEnd(struct Node** head, int data) {
      // allocate memory for node
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      // assign data to newNode
      newNode->data = data;
      // assign null to next of newNode
      newNode->next = NULL;
      // store the head node temporarily (for later use)
      struct Node* temp = *head;
      // if the linked list is empty, make the newNode as head node
      if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
      }
      // if the linked list is not empty, traverse to the end of the linked list
      while (temp->next != NULL)
        temp = temp->next;
      // now, the last node of the linked list is temp
      // assign next of the last node (temp) to newNode
      temp->next = newNode;

      // assign previous of newNode to temp
      newNode->prev = temp;
    }

    // Function to delete a node from the beginning
    void deleteAtBeginning(struct Node** head)
    {
        // checking if the DLL is empty
        if (*head == NULL) {
            printf("The list is already empty.\n");
            return;
        }
    struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }

    // Function to delete a node from the end
    void deleteAtEnd(struct Node** head)
    {
        // checking if DLL is empty
        if (*head == NULL) {
            printf("The list is already empty.\n");
            return;
        }

        struct Node* temp = *head;
        if (temp->next == NULL) {
            *head = NULL;
            free(temp);
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }

// Function to delete a node from a specified position
    void deleteAtPosition(struct Node** head, int position)
    {
        if (*head == NULL) {
            printf("The list is already empty.\n");
            return;
        }
       struct Node* temp = *head;
        if (position == 1) {
            deleteAtBeginning(head);
            return;
        }
        for (int i = 1; temp != NULL && i < position; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position is greater than the number of "
                   "nodes.\n");
            return;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
    }

// print the doubly linked list
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
  // initialize an empty node
  struct Node* head = NULL;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

  // insert 11 after head
  insertAfter(head, 11);

  // insert 15 after the seond node
  insertAfter(head->next, 15);

  displayList(head);

  // delete the last node
  deleteAtBeginning(&head);

  displayList(head);

  deleteAtEnd(&head);
  displayList(head);

  deleteAtPosition(&head,3);
  displayList(head);
}

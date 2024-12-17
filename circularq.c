#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int isFull(int front, int rear)
{
    return (front == (rear + 1) % MAX);
}

int isEmpty(int front)
{
    return front == -1;
}

void enqueue(int queue[], int *front, int *rear, int value)
{
    if (isFull(*front, *rear))
        {
            printf("Queue is full!\n");
        }
    else
        {if (*front == -1) // First insertion
            *front = 0;
        *rear = (*rear + 1) % MAX;
        queue[*rear] = value;
        printf("Inserted %d\n", value);
        }
}


void dequeue(int queue[], int *front, int *rear) {
if (isEmpty(*front))
    {
        printf("Queue is empty!\n");
    }
else
    {
        printf("Deleted %d\n", queue[*front]);
        if (*front == *rear)
            {
                *front = -1;
                *rear = -1;

            }
        else {
                *front = (*front + 1) % MAX;
        }
}
}

void display(int queue[], int front, int rear) {
if (isEmpty(front)) {
printf("Queue is empty!\n");
} else {
printf("Queue elements are: ");
int i = front;
while (i != rear) {
printf("%d ", queue[i]);
i = (i + 1) % MAX;
}
printf("%d\n", queue[i]); // Display last element
}
}

int main() {
int queue[MAX];
int front = -1, rear = -1;
int choice, value;

while (1) {
printf("Enter 1 to enqueue, enter 2 to dequeue, enter 3 to display the contents of the queue and enter 4 to exit queue implementation: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
enqueue(queue, &front, &rear, value);
break;

case 2:
dequeue(queue, &front, &rear);
break;

case 3:
display(queue, front, rear);
break;

case 4:
printf("Exiting queue implementation");
exit(0);
break;

default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}

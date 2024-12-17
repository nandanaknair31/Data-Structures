#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

int isEmpty()
{
    return front==-1;
}

int isFull()
{
    return rear==MAX-1;
}

void enqueue(int value)
{
    if(isFull())
    {
        printf("Queue Overflow \n");
        return;
    }

    if (isEmpty())
    {
        front=0;
    }

    queue[++rear]=value;
    printf("Inserted %d\n", value);

}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow \n");
        return;
    }

    printf("Deleted %d \n", queue[front]);
    if (front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue underflow \n");
        return;
    }

    printf("Queue elements: ");
    for (int i=front; i<=rear; i++)
    {
        printf("%d->", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while(1)
    {
        printf("Enter 1 to enqueue, enter 2 to dequeue, enter 3 to display the contents of the queue and enter 4 to exit the implementation of the queue : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : printf("Enter value to be inserted : ");
                     scanf("%d", &value);
                     enqueue(value);
                     break;

            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("Exiting queue implementation \n");
                     exit(1);
            default : printf("Wrong choice. \n");
        }
    }
}

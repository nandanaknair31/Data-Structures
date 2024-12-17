#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int val)
{
    if (top==MAX-1)
    {
        printf("Stack overflow \n");
        return;
    }
    else
    {
        stack[++top]=val;
        printf("Pushed %d", val);
    }
}

void pop()
{
    if (top ==-1)
    {
        printf("Stack undeflow \n");
        return -1;
    }
    else
    {
        int popped = stack[top--];
        printf("Popped %d", popped);
        return popped;
    }
}

void display()
{
    if (top==-1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Stack elements : ");
        for (int i=0; i<=top; i++)
        {
            printf("%d", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while(1)
    {
        printf("Enter 1 to push, enter 2 to pop, enter 3 to display the contents of the stack, and enter 4 to exit stack implementation : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : printf("Enter the value to be pushed : \n");
                     scanf("%d", &value);
                     push(value);
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("Exiting stack implementation \n");
                     exit(1);
            default : printf("Wrong choice!");
        }
    }
    return 0;
}


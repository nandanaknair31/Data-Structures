#include <stdio.h>
#define MAX 100

void push(char stack[], int top, char c)
{
    if (top< MAX-1)
    {
        stack[++top]=c;
    }
    if (top == MAX-1)
    {
        printf("Stack overflow \n");
        return;
    }
}

char pop(char stack[], int top)
{
    if (top == -1)
    {
        printf("Stack underflow \n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char c)
{
    if (c== '+' ||c=='-')
    {
        return 1;
    }
    else if (c=='*' || c== '/')
    {
        return 2;
    }
    return 0;
}

int isoperator (char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

void infixtopostfix(char *infix, char *postfix, int top)
{
    int i=0, j=0;
    while(infix[i]!=NULL)
    {
        char ch=infix[i];
        if (isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if (ch=='(')
        {
            push(postfix, top, ch);
        }
        else if (ch==')')
        {
            while (top!=-1 && stack[top]!='(')
            {
                postfix[j++]=pop;
            }
            pop();
        }
        else if (isoperator(ch))
        {
            while (top!=-1 && precedence(stack[top]) >=precedence(ch))
            {
                postfix[j++]=pop();
            }
            push(ch);
        }
        i++;
    }
    while (top!=1)
    {
        postfix[j++]=pop();
    }
    postfix[j]=NULL;
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter a valid infix expression : ");
    scanf("%s" infix);
    infixtopostfix(infix, postfix, top);
    printf("Postfix expression : %s \n", postfix);
    return 0;
}

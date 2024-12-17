#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isValid(char *s)
{
    char stack[10000];
    int top=-1;

    for (int i=0; s[i]!=NULL; i++)
    {
        char ch=s[i];
        if(ch=='(' || ch=='[' || ch=='{')
            {
                stack[++top]=ch;
            }
        else
        {
            if (top==-1)
                return false;
            char topchar = stack[top--];
            if ((ch==')' && topchar!= '(')|| (ch==']' && topchar!= '[') || (ch=='}' && topchar!= '{'))
                return false;
        }
    }

return top==-1;
    }

int main()
{
    char str[10000];
    printf("Enter a string using '(', ')', '{', '}', '[',']' to check its validity\n");
    scanf("%s", str);
    bool a =isValid(str);
    if (a)
    {
        printf("The given string is valid \n");
    }
    else
    {
        printf("The given string is invalid \n");
    }
    return 0;
}

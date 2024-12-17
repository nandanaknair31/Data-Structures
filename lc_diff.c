#include <stdio.h>
#include <stdlib.h>

int checker(int *arr,int size, int value)
{
    for (int i=0; i<size; i++)
    {
        if (arr[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

int distinct(int *arr, int sourcesize, int *target, int targetsize, int *result)
{
    int index=0;
    for (int i=0; i<sourcesize; i++)
    {
        if (!(checker(target, targetsize, arr[i])) && !(checker(target, targetsize, arr[i])))
        {
            result[index++]=arr[i];
        }
    }
    return index;
}

int main()
{
    int num1[]={1,2,3};
    int num2[]= {2,4,6};
    int s1=sizeof(num1)/sizeof(num1[0]);
    int s2=sizeof(num2)/sizeof(num2[0]);

    int r1[100], r2[100];
    int sresult1 = distinct(num1, s1, num2, s2, r1);
    int sresult2 = distinct(num2, s2, num1, s1, r2);

    printf("[");
    printf("[");
    for (int i=0; i<sresult1; i++)
    {
        printf("%d", r1[i]);
        if (i<sresult1 - 1)
            printf(",");
    }
    printf("]");

    printf("[");
    for (int i=0; i<sresult2; i++)
    {
        printf("%d", r2[i]);
        if (i<sresult2 - 1)
            printf(",");
    }
    printf("]");
    printf("]\n");

    return 0;
}

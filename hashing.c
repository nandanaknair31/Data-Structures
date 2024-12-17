#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 5

int h[TABLE_SIZE]={NULL};
void insert()
{
    int key,index,i,hkey;
    printf("\nEnter a 4-digit key of the employee to insert into hash table\n");
    scanf("%d",&key);
    if (key<1000 || key>9999)
    {
        printf("Invalid key! Please enter 4-digit employee key");
        return;
    }
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++)
    {
     index=(hkey+i)%TABLE_SIZE;
        if(h[index] == NULL)
        {
        h[index]=key;
         break;
        }

    }
    printf("No of probes for %d is %d", key,i+1);
    if(i == TABLE_SIZE)
    printf("\nElement cannot be inserted\n");

}
void search()
{
int key,index,i,hkey;
printf("\nEnter element to search\n");
scanf("%d",&key);
hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE; i++)
    {
     index=(hkey+i)%TABLE_SIZE;
        if(h[index]==key)
        {
            printf("%d found at index %d",key,index);
            break;
        }
    }
    if(i == TABLE_SIZE)
    printf("\n Value not found\n");
}
void display()
{
    int i;
printf("\nElements in the hash table are \n");
 for(i=0;i< TABLE_SIZE; i++)
 printf("\nAt index %d, value =  %d",i,h[i]);
}
main()
{    int opt,i;
   while(1)
 {        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
      scanf("%d",&opt);
    switch(opt)
    {
     case 1:insert();
            break;
     case 2:display();
            break;
    case 3:search();
            break;
    case 4:exit(0);
    }
 }
}

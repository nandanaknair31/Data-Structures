#include <stdio.h>
#define MAX 5


void dfs(int adj[][MAX], int visited[MAX], int start)
{
    int stack[MAX];
    int top=-1;
    int i;

    stack[++top]=start;
    visited[start]=1;

    while(top!=-1)
    {
        start=stack[top--];
        printf("%d->", start);
        for (i=0; i<MAX; i++)
        {
            if (adj[start][i] && visited[i]==0)
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int adj[MAX][MAX]={{0,1,1,1,0}, {0,0,0,1,0}, {0,1,0,0,0}, {0,0,0,0,1}, {0,0,1,0,0}};
    int visited[MAX]={0};
    int i, b=1;

    printf("DFS Traversal of the given graph is : ");
    dfs(adj, visited, 0);

    printf("NULL\n");

    for (i=0; i<MAX; i++)
    {
        if (visited[i]==0)
        {
            b=0;
        }
    }
    if (b==0)
    {
        printf("The given graph is not connected.");
    }
    else
        printf("The given graph is connected.");

}

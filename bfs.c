#include <stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited [MAX], int start)
{
    int queue[MAX], rear=-1, front=-1, i,k;

    for (k=0; k<MAX; k++)
    {
        visited[k]=0;
    }

    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear >=front)
    {
        start=queue[front++];
        printf("%d->", start);
        for (i=0; i<MAX; i++)
        {
            if (adj[start][i] && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int adj[MAX][MAX]={{0,1,1,1,0}, {0,0,0,1,0}, {0,1,0,0,0}, {0,0,0,0,1}, {0,0,1,0,0}};
    int visited[MAX]={0};

    printf("BFS Traversal of the given graph : ");
    bfs(adj, visited,0);
    printf("NULL\n");
}

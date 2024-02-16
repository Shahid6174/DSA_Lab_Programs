#include <stdio.h>
#include <stdlib.h>

void bfs(int n, int source, int visited[10], int a[10][10], int e[10][2])
{
    int f, r, q[10];
    f = 0;
    r = -1;
    int u, v, k=1;
    visited[source] = 1;
    r += 1;
    q[r] = source;
    while(f<=r)
    {
        u = q[f];
        f += 1; 
        for(v=1; v<=n; v++)
        {
            if(visited[v]==0 && a[u][v] == 1)
            {
                visited[v] = 1;
                r += 1;
                q[r] = v;
                e[k][1] = u;
                e[k][2] = v;
                k += 1;
            }
        }   
    }
}

void dfs(int n, int u, int visited[10], int a[10][10], int e[10][2])
{
    int v;
    static int k = 1;
    visited[u] = 1;
    for(v=1; v<=n; v++)
    {
        if(a[u][v] == 1 && visited[v] == 0)
        {
            e[k][1] = u;
            e[k][2] = v;
            k+=1;
            dfs(n,v,visited,a,e);
        }
    }
}

void main()
{
    int n, i, j, a[10][10], source, visited[10], choice, e[10][2];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);    
    printf("Enter the adjacency Matrix: \n");
    for(i=1; i<=n; i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    for(i=1; i<=n; i++)
    {
        visited[i] = 0;
    }
  
    printf("1.BFS   2.DFS\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice==1)
        bfs(n,source,visited,a,e);
    else
        dfs(n,source,visited,a,e);
    int flag=0;
    for(i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            flag = 1;
            printf("%d is not reachable\n", i);
        }
        else
        {
            printf("%d is reachable.\n", i);
        }
    }
    if(flag == 1)
    {
        printf("Graph is disconnected.\n");
    }
    else
    {
        printf("It is a connected graph.\n");
        printf("The minimum spanning tree is: \n");
        for(int i=1; i<=n-1; i++)
        {
            printf("%d to %d.\n", e[i][1], e[i][2]);
        }
    }
}

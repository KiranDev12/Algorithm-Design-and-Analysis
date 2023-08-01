// Online C compiler to run C program online
#include <stdio.h>
int graph[10][10], visited[10] = {0}, acyclic = 1, n, connected = 1, q[10], f = 0, r = -1,P[10]={-1};
void createGraph()
{
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    printf("Enter the edges\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}
void bfs(int x)
{
    if (!visited[x])
        printf("%d-->", x);
    visited[x] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[x][i] && !visited[i])
        {
            P[i]=x;
            q[++r] = i;
            // printf("\nParent of %d is %d\n",i,P[i]);
        }
        if (graph[x][i] && visited[i])
        {
            if (i != P[x])
            {
                // printf("\n%d %d %d\n", x, i,P[i]);
                acyclic = 0;
            }
        }
    }
    if (f <= r)
    {
        bfs(q[f++]);
    }
}
int main()
{
    createGraph();
    bfs(0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            printf("\n");
            bfs(i);
            printf("\n");
        }
    }
    printf("\n");
    if (acyclic)
        printf("Acyclic\n");
    else
        printf("Cyclic\n");
    if (connected)
        printf("Connected\n");
    else
        printf("DisConnected\n");
    return 0;
}
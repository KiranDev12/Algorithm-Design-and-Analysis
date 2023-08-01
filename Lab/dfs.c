#include <stdio.h>
int graph[10][10], visited[10] = {0}, acyclic = 1, n, connected = 1;
void createGraph()
{
    printf("Enter no of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}
void dfs(int x, int p)
{
    visited[x] = 1;
    printf("--> %d ", x);
    for (int j = 0; j < n; j++)
    {
        if (graph[x][j] && visited[j])
        {
            if (j != p)
            {
                acyclic = 0;
            }
        }
        if (graph[x][j] && !visited[j])
        {
            dfs(j,x);
        }
    }
}

int main()
{
    createGraph();
    dfs(0, -1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]){
            connected=0;
            printf("\n");
            dfs(i,-1);
            printf("\n");
        }
    }
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
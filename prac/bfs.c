#include<stdio.h>

int graph[100][100], n, count=0;
int cyclic = 0;
int visited[100];
void bfs(int start){
	int parent[100], queue[100], front=-1, rear=-1;
	count++;
	visited[start]=1;
	parent[start]=-1;
	rear++;
	queue[rear]=start;
	while(front!=rear){
		front++;
		start=queue[front];
		int parentnode=parent[front];
		printf("-->%d ", start);
		for(int i = 0; i<n; i++){
			if(i!=parentnode && graph[start][i] && visited[i])
				cyclic = 1;
			if(graph[start][i] && !visited[i]){
				rear++;
				queue[rear]=i;
				parent[rear]=start;
				visited[i]=1;
				count++;
			}
		}
	}
}

void main()
{
    int i, j, start;
    printf("Enter the number of nodes : \n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix : \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the starting vertex : \n");
    scanf("%d", &start);
    printf("\nBreadth First Search Traversal: \nStarting Node: %d\n", start);
    bfs(start);
    if (count == n)
        printf("\nGraph is connected");
    else
    {
        printf("\nThe graph is not connected");
        start = 0;
        while (count != n)
        {
            if (visited[start] != 1)
            {
                printf("\nStarting Node: : %d\n", start);
                bfs(start);
            }
            start++;
        }
    }
    if (cyclic == 0)
        printf("\nGraph is Acyclic\n");
    else
        printf("\nGraph is Cyclic\n");
    //printf("Order of count : %d\n", order);
}

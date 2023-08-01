#include<stdio.h>
#include<stdlib.h>
int n;
int graph[100][100], visited[100] = {0}, count = 0;
int cyclic=0;
int stack[100];
int top=-1;
void dfs(int start){
	visited[start]=1;
	for(int i = 0; i<n; i++){
		if(graph[start][i] && !visited[i])
			dfs(i);
	}		
	stack[++top]=start;
}
void detect(int x){
    visited[x]=1;
    for(int j=0;j<n;j++){
        if(graph[x][j] && visited[j]){
            printf("Cycle Exist\n");
            exit(0);
        }
        if (graph[x][j] && !visited[j])
        {
            detect(j);
        }
    }
    visited[x]=0;
}
void main()
{
	int i;
	printf("Enter the number of nodes : \n");
  	scanf("%d", &n);
  	printf("Enter the Adjacency Matrix : \n");
  	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
     			 scanf("%d", &graph[i][j]);
     	detect(0);
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			dfs(i); // calling dfs on all unvisited vertices
	}

	printf("Topologically sorted order\n");
	for (i = 0; i < n; i++)
		printf("%d --> ", stack[i]); // printing stack (taken as array for simplicity) in reverse order
}

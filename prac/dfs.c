#include<stdio.h>
int n;
int graph[100][100], visited[10]={0};
int cyclic = 0;
int start, count = 0;
void dfs(int start, int prev){
	count++;
	visited[start]=1;
	printf("-->%d", start);
	for(int i = 0; i < n; i++){
		if(i!=prev && graph[start][i] && visited[i])
			cyclic = 1;
		if(graph[start][i] && !visited[i])
			dfs(i, start);
	}
}
void main(){
	printf("Enter the number of vertices in the graph: \n");
	scanf("%d", &n);
	printf("Enter the adj matrix of the graph: \n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	printf("Enter the starting vertex: \n");
	scanf("%d", &start);
	dfs(start, -1);
	if(count==n)
		printf("The graph is connected\n");
	else{
		printf("\nThe graph is disconnected. Other components: \n");
		start=0;
		while(count!=n){
			if(visited[start]!=1){
				printf("\nStarting Node: : %d\n", start);
				dfs(start, -1);
			}
			start++;
		}
	}
	if(cyclic==1){
		printf("The graph is cyclic\n");
	}
	else{
		printf("The graph is acyclic\n");
	}
}

#include<stdio.h>
int graph[100][100];
int p[100][100];

int min(int a, int b){
	return (a>b)?b:a;
}
void main(){
	int n;
	printf("Enter the number fo vertices: \n");
	scanf("%d", &n);
	printf("Enter the adj matrix: \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &graph[i][j]);
			p[i][j]=graph[i][j];
		}	
	}
	printf("Applying Floyd's Algorithm\n");
	for(int k=0; k<n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				p[i][j] = min(p[i][j], (p[i][k] + p[k][j]));
			}	
		}
	}
	printf("Transitive Closure matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			printf("%d ",p[i][j]);
		}
		printf("\n");	
	}
}

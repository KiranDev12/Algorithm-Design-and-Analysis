#include <stdio.h>
#include <stdlib.h>

int cost[10][10], n, min_cost = 0, min, a, b, visited[10] = {0}, edges = 0;

void createGraph()
{
	int i, j;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter cost Matrix: \n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = 1000;
		}
	}
}

void main(){

  int i, j;
	createGraph();

	visited[0] = 1;

  while (edges < n-1)
  {
    for (int i = 0; i < n; i++)
    {
      min=1000;
      if (visited[i])
      {
        for (int j = 0; j < n; j++)
        {
          if (min>cost[i][j] && !visited[j])
          {
            min = cost[i][j];
            a=i;
            b=j;
          }   
        }
        
      }
      
    }
    printf("%d->%d == %d", a, b, cost);
    visited[b]=1;
    edges++;
    min_cos+=min;
  }
  
}
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

void main()
{
	int i, j;
	createGraph();

	visited[0] = 1;
	while (edges < n - 1) // in a minimum spanning tree(MST), edges=vertices-1
	{
		min = 1000;
		for (i = 0; i < n; i++) // traversing the list of vertices and searching for src vertices i.e traversed/visited vertices
		{
			if (visited[i]) // checking if the source vertex is visited, as an outgoing edge is possible only when the src vertex is traversed
			{
				for (j = 0; j < n; j++) // finding destination vertex
				{
					if (cost[i][j] < min && !visited[j]) // ensuring that destination vertex is unvisited else if both src and destination vertices are visited then it'll result in a cycle
					{
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}

		printf("%d -> %d : Cost-%d\n", a, b, min);
		min_cost += min;
		visited[b] = 1;
		edges++;
	}

	printf("Minimum Cost: %d\n", min_cost);
}
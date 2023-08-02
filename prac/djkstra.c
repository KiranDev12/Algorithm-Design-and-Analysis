#include <stdio.h>

void djkstra(int n, int cost[10][10], int distance[10], int s)
{

  int v, edges = 1, visited[100] = {0};
  int min;
  for (int i = 0; i < n; i++)
  {
    distance[i] = cost[s][i];
  }

  visited[s] = 1;
  distance[s] = 0;

  while (edges < n)
  {
    min = 999;
    for (int i = 0; i < n; i++)
    {
      if (distance[i] < min && !visited[i])
      {
        min = distance[i];
        v = i;
      }
    }
    visited[v] = 1;
    edges++;

    for (int i = 0; i < n; i++)
    {
      if (distance[i] > distance[v] + cost[v][i])
      {
        distance[i] = distance[v] + cost[v][i];
      }
    }
  }
}
void main()
{
    int i, j, n, s,  dist[10]; // dist stores the distance from source vertex to the given vertex
    // cost matrix stores the cost of each edge(weight) and if no edge exists then the user enters 0, and is then converted to 999(which represents infinity)

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    int cost[10][10]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    printf("Read the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        { // Corrected loop bound
            // scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    djkstra(n, cost, dist, s);

    printf("Shortest path from %d is:\n", s);
    for (i = 1; i <= n; i++)
    {
        if (s != i)
            printf("%d -> %d = %d\n", s, i, dist[i]); // Added newline character
    }
}
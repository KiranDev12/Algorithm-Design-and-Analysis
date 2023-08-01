#include <stdio.h>
int main()
{
    int cost[10][10], visited[10] = {0}, i, j, n, no_e = 1, min, a, b, min_cost = 0;
    printf("Enter number of vertices ");
    scanf("%d", &n);
    printf("Enter weighted matrix in form of adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 1000;
        }
    visited[1] = 1;
    while (no_e < n)
    {
        min = 1000;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min && visited[i])
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        if (visited[b] == 0)
        {
            printf("\n%d to %d  cost=%d", a, b, min);
            min_cost = min_cost + min;
            no_e++;
        }
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 1000;
    }
    printf("\nminimum weight is %d", min_cost);
}

// {0,3,0,0,6,5},
// 		{3,0,1,0,0,4},
// 		{0,1,0,6,0,4},
// 		{0,0,6,0,8,5},
// 		{6,0,0,8,0,2},
// 		{5,4,4,5,2,0}
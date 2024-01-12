#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i, j, u, v, a, b, n, ne = 1;
    int min, mincost = 0, visited[10] = {0}, cost[10][10];

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("\nEnter Adjacency Matrix: ");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &cost[i][j]);
            
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;

    while (ne < n)
    {
        for(i=1, min=999; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("\n\nEdge %d: (%d %d): cost = %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMinimum cost = %d", mincost);
}
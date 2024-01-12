#include<stdio.h>
#include<stdlib.h>

void dijikstras(int cost[10][10], int n, int startnode)
{
    int i, j, distance[10], pred[10], visited[10], mindist, count, nextnode;

    for(i=0; i<n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while(count < n-1)
    {
        mindist = 999;
        for(i=0; i<n; i++)
        {
            if(distance[i]<mindist && !visited[i])
            {
                mindist = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(mindist+cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
            count++;
        }
    }

    for(i=0; i<n; i++)
    {
        if(i != startnode)
        {
            printf("\n\nDistance of %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do
            {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startnode);
            
        }
    }
}

void main()
{
    int i, j, n, G[10][10], source;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("\nEnter Adjacency Matrix: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &G[i][j]);
            if(G[i][j] == 0)
                G[i][j] = 999;
        }
    }

    printf("\n\nEnter source vertex: ");
    scanf("%d", &source);

    dijikstras(G, n, source);

}
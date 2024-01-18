#include<stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int p[10], int wt[10])
{
    if(n == 0 || W == 0)
        return 0;

    if(wt[n-1] > W)
        return knapsack(n-1, W, p, wt);
    else
        return max(p[n-1]+knapsack(n-1, W-wt[n-1], p, wt), knapsack(n-1, W, p, wt));
}

void main()
{
    int i, j, n;
    int profit[10], weight[10], m;

    printf("Enter no. of objects: ");
    scanf("%d", &n);

    printf("\nEnter Profits and Weights of %d objects: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%f %f", &profit[i], &weight[i]);
    }

    printf("\nEnter Maximum Capacity: ");
    scanf("%f", &m);

    printf("%d", knapsack(n, m, profit, weight));

    // return 0;
}
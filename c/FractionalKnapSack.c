#include<stdio.h>
#include<stdlib.h>

void knapsack(int n, float max_w, float profit[10], float weight[10])
{
    float tot_p, x[10] = {0};
    int i;

    for(i=0; i<n; i++)
    {
        if(weight[i] > max_w)
            break;
        else
        {
            x[i] = 1;
            max_w -= weight[i];
            tot_p += profit[i];
        }
    }

    if(i < n)
        x[i] = max_w / weight[i];
    tot_p += (x[i] * profit[i]);

    printf("\n\nThe result vector is: ");
    for(i=0; i<n; i++)
    {
        printf("%f\t", x[i]);
    }

    printf("\nThe Total Profit is: %f", tot_p);
    
}

void main()
{
    int i, j, n;
    float ratio[10], profit[10], weight[10], temp, m;

    printf("Enter no. of objects: ");
    scanf("%d", &n);

    printf("\nEnter Profits and Weights of %d objects: ", n);
    for(i=0; i<n; i++)
    {
        scanf("%f %f", &profit[i], &weight[i]);
    }

    printf("\nEnter Maximum Capacity: ");
    scanf("%f", &m);

    for(i=0; i<n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
                
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    knapsack(n, m, profit, weight);

}
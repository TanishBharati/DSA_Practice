#include<stdio.h>

int A[10][10],M[10][10],N[10][10],Av[10],nop,nor;

void acceptData(int X[][10])
{
    int i,j;
    for(i=0; i<nop; i++)
    {
        printf("P%d\n",i);
        for(j=0; j<nor; j++)
        {
            printf("%c:",65+j);
            scanf("%d",&X[i][j]);
        }
    }
}

void acceptAvail()
{
    int i;
    for(i=0; i<nor; i++)
    {
        printf("%c:",65+i);
        scanf("%d",&Av[i]);
    }
}

void displayData()
{
    int i,j;
    printf("\n\tAllocation\t\tMax\t\tNeed\n");
    printf("\t");

    for(i=0; i<3; i++)
    {
        for(j=0; j<nor; j++)
        {
            printf("%c",65+j);
        }
        printf("\t");
    }

    for(i=0; i<nop; i++)
    {
        printf("\nP%d\t",i);

        for(j=0; j<nor; j++)
        {
            printf("%4d",A[i][j]);
        }
        printf("\t");

        for(j=0; j<nor; j++)
        {
            printf("%4d",M[i][j]);
        }
        printf("\t");

        for(j=0; j<nor; j++)
        {
            printf("%4d",N[i][j]);
        }
    }
    printf("\nAvailable\n");
    for(i=0; i<nor; i++)
    {
        printf("%4d",Av[i]);
    }

}

void calcNeed()
{
    int i,j;
    for(i=0; i<nop; i++)
    {
        for(j=0; j<nor; j++)
        {
            N[i][j] = M[i][j] - A[i][j];
        }
    }
}

int main()
{
    printf("Enter no. of processes: ");
    scanf("%d",&nop);
    printf("Enter no. of resources: ");
    scanf("%d",&nor);
    printf("Enter Allocation:\n");
    acceptData(A);
    printf("Max Requirements:\n");
    acceptData(M);
    calcNeed();
    displayData();
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 40

void CountSort(int a[], int n)
{
    int output[10], count[20], max, i;
    
    max = a[0];
    for(i=1; i<n;i++)
    {
        if(max < a[i])
            max = a[i];
    }

    for(i=0; i<=max; i++)
    {
        count[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        count[a[i]]++;
    }
    for(i=1; i<=max; i++)
    {
        count[i] += count[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        output[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for(i=0; i<n; i++)
    {
        a[i] = output[i];
    }
}

void csort(int a[], int n, int place)
{
    int output[MAX], count[MAX], i;
    int max = (a[0] / place) % 10;

    for(i=1; i<n; i++)
    {
        if(((a[i] / place) % 10) > max)
            max = a[i];
    }

    for(i=0; i<max; i++)
    {
        count[i] = 0;
    }

    for(i=0; i<n; i++)
    {
        count[(a[i] / place) % 10]++;
    }
    for(i=1; i<20; i++)
    {
        count[i] += count[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        output[count[(a[i]/place) % 10] - 1] = a[i];
        count[(a[i] /place) % 10]--;
    }

    for(i=0; i<n; i++)
        a[i] = output[i];

}

void RadixSort(int a[], int n)
{
    int i,place, max = a[0];

    for (i=1; i<n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    for(place=1; max/place>0; place*=10)
    {
        csort(a, n, place);
    }
    
}

int maxElem(int a[], int n)
{
    int i, max = a[0];

    for(i=1; i<n; i++)
    {
        if(max < a[i])
            max = a[i];
    }
    return max;
}

void BucketSort(int a[], int n)
{
    int i, j;
    int max = maxElem(a, n);

    int* count = (int*)malloc(max * sizeof(int*));

    for(i=0; i<=max; i++)
        count[i] = 0;

    for(i=0; i<n; i++)
        count[a[i]]++;

    for(i=0, j=0; i<=max; i++)
    {
        while(count[i] > 0)
        {
            a[j] = i;
            j++;
            count[i]--;
        }
    }
}

void printArray(int a[], int n)
{   
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[20], i, j, size, choice;
    clock_t start, end;
    float timeTaken;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The given array is: \n");
    printArray(arr, size);

    do
    {
        printf("Select the Linear Sorting algorithm to sort the array: \n");
        printf("1. Count Sort\n2. Radix Sort\n3. Bucket Sort\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = 0; end = 0; timeTaken = 0;
            start = clock();
            CountSort(arr, size);
            clock_t end = clock();
            timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printArray(arr, size);
            printf("Time compl. = %f\n\n", timeTaken);
            break;
        
        case 2:
            start = 0; end = 0; timeTaken = 0;
            start = clock();
            RadixSort(arr, size);
            end = clock();
            timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printArray(arr, size);
            printf("Time compl. = %f\n\n", timeTaken);
            break;

        case 3:
            start = 0; end = 0; timeTaken = 0;
            start = clock();
            BucketSort(arr, size);
            end = clock();
            timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printArray(arr, size);
            printf("Time compl. = %f\n\n", timeTaken);
            break;

        case 4:
            exit(0);
            break;    

        default:
            printf("Invalid Choice... Try again!");
            break;
        }
    } while (choice != 4);

    return 0;
    
}


// int bucketCount = 10; //no. of buckets
//     int i, j;

//     int** bucket = (int **)malloc(bucketCount * sizeof(int *));
//     for(i=0; i<bucketCount; i++)
//         bucket[i] = (int *)malloc(n * sizeof(int *));

//     for(i=0; i<bucketCount; i++)
//     {
//         for(j=0; j<n; j++)
//         {
//             bucket[i][j] = 0;
//         }
//     }

//     for(i=0; i<n; i++)
//     {
//         bucket[a[i]]++;
//     }

//     for(i=0, j=0; i<n; i++)
//     {
//         while()
//     }
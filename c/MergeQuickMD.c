#include<stdio.h>
#include<stdlib.h>

void QuickSort()
{}

void merge(int a[], int low, int mid, int high)
{
    int b[20], i = low, j = mid + 1, p;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++; k++;
        }
        else
        {
            b[k] = a[j];
            j++; k++;
        }
    }

    while(i <= mid)
    {
        b[k] = a[i];
        i++; k++;
    }
    while(j <= high)
    {
        b[k] = a[j];
        j++; k++;
    }

    for(p=low; p<=high; p++)
    {
        a[p] = b[p];
    }
}

void MergeSort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        merge(a,  low, mid, high);
    }
}

int maxElem(int a[], int n)
{
    int i, max = a[0];

    for(i=1; i<n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    return max;
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

// int main()
// {
//     int arr[20], i, j, size, choice, high;

//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     printf("Enter %d elements: ", size);
//     for(i=0; i<size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("The given array is: \n");
//     printArray(arr, size);

//     do
//     {
//         printf("Select the Merge OR Quick sort algorithms to sort the array: \n");
//         printf("1. Merge Sort\n2. Quick Sort\n3. Exit\n");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             high = maxElem(arr, size);
//             MergeSort(arr, 0, high);
//             printArray(arr, size);
//             break;
        
//         case 2:
//             QuickSort(arr, size);
//             printArray(arr, size);
//             break;

//         case 3:
//             exit(0);
//             break;    

//         default:
//             printf("Invalid Choice... Try again!");
//             break;
//         }
//     } while (choice != 3);

//     return 0;
    
// }

int main()
{
    int a[] = {19, 26, 24, 97, 46, 92, 4, 39, 46};
    int n = 9;

    printArray(a, n);
    MergeSort(a, 0, n-1);
    printArray(a, n);
    
    return 0;
}
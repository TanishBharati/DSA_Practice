#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[], int n)
{
    int i, j, temp = 0;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Array after sorting using Bubble Sort is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void SelectionSort(int a[], int n)
{
    int i, j;
    
    for(i=0; i<n-1; i++)
    {
        int min = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Array after sorting using Selection Sort is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void InsertionSort(int a[], int n)
{
    int i, j, key;
    
    for(i=1; i<n; i++)
    {
        key = a[i];
        j = i-1;

        while((a[j] > key) && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    printf("Array after sorting using Insertion Sort is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
} 

void HeapSort(int a[], int n)
{
    int i;

    // build max heap
    for(i=n/2-1; i>=0; i--)
    {
        heapify(a, n, i);
    }

    // heap sort
    for(i=n-1; i>=0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }

    printf("Array after sorting using Heap Sort is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[20], i, j, size, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements: ", size);
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The given array is: \n");
    for(i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    do
    {
        printf("Select the Sorting algorithm to sort the array: \n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Heap Sort\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                BubbleSort(arr, size);
                break;

            case 2:
                SelectionSort(arr, size);
                break;

            case 3:
                InsertionSort(arr, size);
                break;

            case 4:
                HeapSort(arr, size);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice... Try again!");
                break;
        }
    } while (choice != 5);

    return 0;
    
}
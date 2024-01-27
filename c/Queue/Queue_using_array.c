#include<stdio.h>
#include<stdlib.h>

int queue[20], top = -1, rear = -1, choice, size;

void enqueue()
{
    int data;
    
    if(rear == size - 1)
    {
        printf("\nOverflow...\n\n");
        return;
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &data);

        if(top == -1 && rear == -1)
        {
            top = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        queue[rear] = data;

        printf("\nValue inserted successfully!\n");
    }
}

void dequeue()
{
    if(top == -1 || top > rear)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else
    {
        int val = queue[top];

        if(top == rear)
        {
            top = -1;
            rear = -1;
        }
        else
        {
            top++;
        }

        printf("\nItem %d dequeued successfully!\n", val);
    }
}

void display()
{
    if(rear == -1)
    {
        printf("\nEmpty Queue!\n\n");
        return;
    }
    else
    {
        for(int i=top; i<=rear; i++)
        {
            printf("%d -> ", queue[i]);
        }

        printf("Null");
    }
    
}

int main()
{
    printf("____________Menu Driven for Queue Implementation using Array!!____________\n\n");

    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    do
    {
       printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice)
       {
        case 1:
            enqueue();
            break;
       
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);
            break;
       }
    } while (choice != 4);
    
    return 0;
}
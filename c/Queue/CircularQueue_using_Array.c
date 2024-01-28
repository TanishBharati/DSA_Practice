#include<stdio.h>
#include<stdlib.h>

int cQueue[20], size;
int front = -1;
int rear = -1;

void enqueue()
{
    int data;
    
    printf("\nEnter value: ");
    scanf("%d", &data);

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if((rear + 1) % size == front)
    {
        printf("\nOverflow...\n\n");
        return;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    cQueue[rear] = data;

    printf("\nValue enqueued successfully!\n");
}

void dequeue()
{
    if(front == -1)
    {
        printf("\nUnderflow...\n\n");
    }
    else if(front == rear)
    {
        printf("\nValue %d dequeued successfully!\n", cQueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nValue %d dequeued successfully!\n", cQueue[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    int i;
    
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    else
    {
        i = front;

        while(i != rear)
        {
            printf("%d -> ", cQueue[i]);
            i = (i + 1) % size;
        }

        printf("%d -> Null\n", cQueue[i]);
    }
}

int main()
{
    int choice;
    
    printf("____________Menu Driven for Cicular Queue Implementation using Array!!____________\n\n");

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
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue* next;
}Queue;

Queue* front;
Queue* rear;

void enqueue()
{
    int data;
    Queue* node = (Queue *)malloc(sizeof(Queue));

    printf("\nEnter value: ");
    scanf("%d", &data);

    node->data = data;

    if(front == NULL)
    {
        front = node;
        rear = node;
        front->next = rear->next = NULL;
    }
    else
    {
        rear->next = node;
        rear = node;
        rear->next = NULL;
    }

    printf("\nValue inserted successfully!\n\n");
}

void dequeue()
{
    Queue* ptr;
    
    if(front == NULL)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;

        printf("\nItem %d dequeued successfully!\n\n", ptr->data);
        free(ptr);
    }
}

void display()
{
    Queue* temp;

    if(front == NULL)
    {
        printf("\nQueue is Empty!\n\n");
        return;
    }
    else
    {
        temp = front;

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        
        printf("Null");
    }
}

int main()
{
    int choice;
    
    printf("____________Menu Driven for Queue Implementation using Linked List!!____________\n\n");

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

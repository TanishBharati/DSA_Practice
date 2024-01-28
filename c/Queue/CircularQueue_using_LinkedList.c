#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue* next;
}Queue;

Queue* front = NULL;
Queue* rear = NULL;

void enqueue()
{
    int data;
    Queue* node = (Queue *)malloc(sizeof(Queue));

    printf("\nEnter value: ");
    scanf("%d", &data);

    node->data = data;

    if(front == NULL && rear == NULL)
    {
        front = node;
        rear = node;
        rear->next = front;
    }
    else
    {
        rear->next = node;
        rear = node;
        rear->next = front;
    }

    printf("\nValue enqueued successfully!\n");
}

void dequeue()
{
    Queue* temp = front;

    if(front == NULL && rear == NULL)
    {
        printf("\nUnderflow...\n\n");
    }
    else if(front == rear)
    {
        printf("\nValue %d dequeued successfully!\n", front->data);
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        printf("\nValue %d dequeued successfully!\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("\nQueue is Empty!\n\n");
        return;
    }
    else
    {
        printf("\nTop Element = %d\n\n", front->data);
    }

}

void display()
{
    Queue* curr;

    if(front == NULL && rear == NULL)
    {
        printf("\nQueue is Empty!\n\n");
        return;
    }
    else
    {
        curr = front;

        while (curr->next != front)
        {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        
        printf("%d -> NULL\n", curr->data);
    }
}

int main()
{
    int choice;
    
    printf("____________Menu Driven for Cicular Queue Implementation using Linked List!!____________\n\n");
    do
    {
       printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n\n");
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
            peek();
            break;
        
        case 4:
            display();
            break;

        case 5:
            exit(1);
            break;
       }
    } while (choice != 5);
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int deque[20], size;
int front = -1;
int rear = -1;

void enqueue_front()
{
    int data;
    
    if((front == rear + 1) || (front == 0 && rear == size - 1))
    {
        printf("\nOverflow...\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        
        front = rear = 0;
        deque[front] = data;
    }
    else if(front == 0)
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        
        front = size - 1;
        deque[front] = data;
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        
        front -= 1;
        deque[front] = data;
    }

    printf("\nValue enqueued successfully!\n");
}

void enqueue_rear()
{
    int data;
    
    if((front == rear + 1) || (front == 0 && rear == size - 1))
    {
        printf("\nOverflow...\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        
        front = rear = 0;
        deque[rear] = data;
    }
    else if(rear == size - 1)
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        
        rear = 0;
        deque[rear] = data;
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &data);

        rear += 1;
        deque[rear] = data;
    }

    printf("\nValue enqueued successfully!\n");
}

void dequeue_front()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else if(front == rear)
    {
        printf("\nValue %d dequeued successfully!\n", deque[front]);
        front = rear = -1;
    }
    else if(front == size - 1)
    {
        printf("\nValue %d dequeued successfully!\n", deque[front]);
        front = 0;
    }
    else
    {
        printf("\nValue %d dequeued successfully!\n", deque[front]);
        front += 1;
    }

}

void dequeue_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else if(front == rear)
    {
        printf("\nValue %d dequeued successfully!\n", deque[rear]);
        front = rear = -1;
    }
    else if(rear == 0)
    {
        printf("\nValue %d dequeued successfully!\n", deque[rear]);
        rear = size - 1;
    }
    else
    {
        printf("\nValue %d dequeued successfully!\n", deque[rear]);
        rear -= 1;
    }
}

void peek_front()
{
    if(front == -1 && rear == -1)
    {
        printf("\nDeque is Empty!\n\n");
        return;
    }
    else
    {
        printf("\nElement at Front End = %d\n\n", deque[front]);
    }
}

void peek_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("\nDeque is Empty!\n\n");
        return;
    }
    else
    {
        printf("\nElement at Front End = %d\n\n", deque[rear]);
    }
}

void display()
{
    int i;

    if(front == -1 && rear == -1)
    {
        printf("\nDeque is Empty!\n\n");
        return;
    }
    else
    {
        i = front;

        while(i != rear)
        {
            printf("%d -> ", deque[i]);
            i = (i + 1) % size;
        }

        printf("%d -> Null\n", deque[i]);
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
       printf("\n1. Enqueue at Front End\n2. Enqueue at Rear End\n3. Dequeue at Front End\n4. Dequeue at Rear End\n5. Peek at Front\n6. Peek at Rear\n7. Display\n8. Exit\n\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice)
       {
        case 1:
            enqueue_front();
            break;
        
        case 2:
            enqueue_rear();
            break;
       
        case 3:
            dequeue_front();
            break;
        
        case 4:
            dequeue_rear();
            break;
        
        case 5:
            peek_front();
            break;
        
        case 6:
            peek_rear();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(1);
            break;
       }
    } while (choice != 8);
    
    return 0;
}
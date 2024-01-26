#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack* next;
}Stack;

Stack* top;

void push()
{
    int data;
    Stack* item = (Stack *)malloc(sizeof(Stack));

    printf("\nEnter value: ");
    scanf("%d", &data);

    item->data = data;

    if(top == NULL)
    {
        item->next = NULL;
        top = item;
    }
    else
    {
        item->next = top;
        top = item;
    }

    printf("\nValue inserted successfully!\n\n");
}

void pop()
{
    Stack* temp;
    
    if(top == NULL)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else
    {
        temp = top;
        top = top->next;

        printf("Value %d popped successfully!", temp->data);
        free(temp);
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("\nStack is empty!\n\n");
        return;
    }
    else
    {
        printf("\nTop Element = %d\n\n", top->data);
    }
}

void show()
{
    Stack* temp;

    if(top == NULL)
    {
        printf("\nStack is empty!\n\n");
        return;
    }
    else
    {
        temp = top;

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    
    printf("____________Menu Driven for Stack Implementation using Linked List!!____________\n\n");

    do
    {
       printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice)
       {
        case 1:
            push();
            break;
       
        case 2:
            pop();
            break;

        case 3:
            peek();
            break;
        
        case 4:
            show();
            break;

        case 5:
            exit(1);
            break;
       }
    } while (choice != 5);
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

int stack[100], size, choice, i, top = -1;

void push()
{
    if(top == size - 1)
    {
        printf("\nOverflow...\n\n");
        return;
    }
    else
    {
        int val;

        printf("\n\nEnter value: ");
        scanf("%d", &val);

        stack[++top] = val;

        printf("\nElement pushed successfully!\n\n");
    }

}

void pop()
{
    if(top == -1)
    {
        printf("\nUnderflow...\n\n");
        return;
    }
    else
    {
        int item = stack[top];
        top--;
        
        printf("\nItem %d deleted successfully!\n\n", item);
    }
}

void peek()
{
    if(top == -1)
    {
        printf("\nStack is empty!\n\n");
        return;
    }
    else
    {
        printf("Top element = %d", stack[top]);
    }
}

void show()
{
    if(top == -1)
    {
        printf("\nStack is empty!\n\n");
        return;
    }
    else
    {
        for(i=top; i>=0; i--)
        {
            printf("%d\n", stack[i]);
        }

        printf("\n");
    }
}

int main()
{
    printf("____________Menu Driven for Stack Implementation using Array!!____________\n\n");

    printf("Enter the size of Stack: ");
    scanf("%d", &size);

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
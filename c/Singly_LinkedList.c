#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head;

void push_front()
{
    int data;
    Node* new_node = (Node *)malloc(sizeof(Node *));

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);

    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void push_back()
{
    int data;
    Node* temp; 
    Node* new_node = (Node *)malloc(sizeof(Node *));

    printf("Enter the element to be inserted: ");
    scanf("%d", &data);

    new_node->data = data;
    if(head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->next = NULL;
        temp->next = new_node;
    }
}

void pop()
{}

void search()
{}

void length()
{}

void display()
{
    Node* curr = head;

    while(curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }

    printf("null\n\n");
}

void main()
{
    int choice;
    
    printf("____________Menu Driven for Singly Linked List____________\n\n");

    do
    {
       printf("1. Insert in front\n2. Insert at last\n3. Delete\n4. Search\n5. Length\n6. Display List\n7. Exit\n\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch(choice)
       {
        case 1:
            push_front();
            break;
       
        case 2:
            push_back();
            break;

        case 3:
            pop();
            break;

        case 4:
            search();
            break;

        case 5:
            length();
            break;

        case 6:
            display();
            break;

        case 7:
            exit(1);
       }
    } while (choice != 7);
    
}

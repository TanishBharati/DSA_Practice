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

void pop_front()
{
    Node* ptr;

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("The only element in the list removed\n\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        printf("Item %d removed\n\n", ptr->data);
        free(ptr);
    }
}

void pop_back()
{
    int item;
    Node* ptr;
    Node* temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("The only element in the list removed\n\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }

        ptr->next = NULL;
        item = temp->data;
        free(temp);

        printf("Item %d removed\n\n", item);
    }

   
}

void search()
{
    int element, i=0, flag = 0;
    Node* curr = head;

    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else
    {
        while(curr != NULL)
        {
            if(curr->data == element)
            {
                printf("%d element found at index %d\n\n", element, i);
                flag = 1;
            }
            curr = curr->next;
            i++;
        }
        if(flag == 0)
        {
            printf("Element not found in the list\n\n");
            return;
        }
    }
}

void length()
{
    int length = 0;
    Node* temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else
    {
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }

        printf("The length of list is %d\n\n", length);
        return;
    }
}

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
       printf("1. Insert in front\n2. Insert at last\n3. Delete at front\n4. Delete at last\n5. Search\n6. Length\n7. Display List\n8. Exit\n\n");
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
            pop_front();
            break;
        
        case 4:
            pop_back();
            break;

        case 5:
            search();
            break;

        case 6:
            length();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(1);
       }
    } while (choice != 8);
    
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* head;

void push_front()
{
    int data;
    Node* new_node = (Node *)malloc(sizeof(Node *));

    printf("Enter the element to be inserted at start: ");
    scanf("%d", &data);

    new_node->data = data;

    if(head == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
    printf("\nElement inserted successfully!\n\n");
}

void push_back()
{
    int data;
    Node* temp;
    Node* new_node = (Node *)malloc(sizeof(Node *));

    printf("Enter the element to be appended at last: ");
    scanf("%d", &data);

    new_node->data = data;

    if(head == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
    }
    else
    {
        temp = head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->prev = temp;
        temp->next = new_node;
        new_node->next = NULL;
    }

    printf("\nElement inserted successfully!\n\n");
}

void pop_front()
{
    Node* temp;

    if(head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("The only element in the list deleted successfully!");
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Item %d deleted successfully!\n\n", temp->data);
        free(temp);
    } 
}

void pop_back()
{
    Node* temp;

    if(head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }
    else if(head->next == NULL)
    {
        free(head);
        printf("The only element in the list deleted successfully!");
        return;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        printf("Item %d deleted successfully!\n\n", temp->data);
        free(temp);
    }
}

void search()
{
    int element, i=0, flag = 0;
    Node* ptr = head;

    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    while(ptr != NULL)
    {
        if(ptr->data == element)
        {
            printf("Element %d found at index %d", element, i);
            flag = 1;
            return;
        }
        
        i++;
        ptr = ptr->next;
    }

    if(flag == 0)
    {
        printf("Element %d not found in the list\n\n");
        return;
    }
}

void size()
{
    int size = 0;
    Node* ptr = head;

    if(head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }
    else
    {
        while(ptr != NULL)
        {
            size++;
            ptr = ptr->next;
        }

        printf("The size of the list is %d\n\n", size);
        return;
    }
    
}

void display()
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("Null\n\n");
}

void main()
{
    int choice;
    
    printf("____________Menu Driven for Doubly Linked List____________\n\n");

    do
    {
       printf("1. Insert in front\n2. Append at last\n3. Delete at front\n4. Delete at last\n5. Search\n6. Size\n7. Display List\n8. Exit\n\n");
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
            size();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(1);
       }
    } while (choice != 8);
    
}

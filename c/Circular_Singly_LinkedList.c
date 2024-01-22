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
    Node* temp;
    Node* new_node = (Node *)malloc(sizeof(Node));

    printf("Enter the element to be inserted at start: ");
    scanf("%d", &data);

    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    printf("\nElement inserted successfully!\n\n");
}

void push_back()
{
    int data;
    Node* temp;
    Node* new_node = (Node *)malloc(sizeof(Node));

    printf("Enter the element to be appended at last: ");
    scanf("%d", &data);

    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = head;
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
    else if(head->next == head)
    {
        // head = NULL;
        free(head);
        printf("The only element in the list deleted successfully!\n\n");
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        printf("Item %d deleted successfully!\n\n", temp->data);
        free(temp);
    }
}

void pop_back()
{
    Node* ptr;
    Node* temp;

    if(head == NULL)
    {
        printf("List is empty!\n\n");
        return;
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("The only element in the list deleted successfully!\n\n");
        return;
    }
    else
    {
        temp = head;
        
        while(temp->next != head)
        {
            ptr = temp;
            temp = temp->next;
        }

        ptr->next = temp->next;

        printf("Item %d deleted successfully!\n\n", temp->data);
        free(temp);
    }
    
}

void search()
{
    int element, i = 0, flag = 0;
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
        while(curr->next != head)
        {
            if(curr->data == element)
            {
                printf("%d element found at index %d\n\n", element, i);
                flag = 1;
                return;
            }

            i++;
            curr = curr->next;
        }
        
        if(curr->data == element)
        {
            printf("%d element found at index %d\n\n", element, i);
            return;
        }

        if (flag == 0)
        {
            printf("Element not found in the list\n\n");
            return;
        }
        
    }
}

void size()
{
    int size = 0;
    Node* curr = head;

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else
    {
        while (curr->next != head)
        {
            size++;
            curr = curr->next;
        }

        printf("The size of list is %d\n\n", size + 1);
        return;
    }
}

void display()
{
    Node* temp;

    if(head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }

        printf("%d->Null\n\n", temp->data);
    }
}

int main()
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
    
    return 0;
}
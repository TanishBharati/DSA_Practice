#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data)
{
    Node* new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

void preorder(Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    //Creating nodes
    Node* p = createNode(5);
    Node* p1 = createNode(2);
    Node* p2 = createNode(6);
    Node* p3 = createNode(1);
    Node* p4 = createNode(8);
    Node* p5 = createNode(9);
    Node* p6 = createNode(3);

    //Connnecting nodes through links
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    /* Tree representation -      
            5
           /  \
         2      6
        / \    / \
       1   8  9    3
    */
   
    printf("Preorder Traversal:\n");
    preorder(p);
    
    printf("\nPostorder Traversal:\n");
    postorder(p);

    printf("\nInorder Traversal:\n");
    inorder(p);

    return 0;
}


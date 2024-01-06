//Implementation of AVL Tree
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b){
    return (a>b)?a:b;
}

int height(struct Node *node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalance(struct Node *node){
   if( node == NULL) return 0;
   return height(node->left) - height(node->right);
}

struct Node *newNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node ->height = 1;
    return node;
}

struct Node *rotateRight(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2= x->right;
    //Perform rotation
    x->right = y;
    y->left = T2;
    /* Update heights */
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *rotateLeft(struct Node *x){
    struct Node *y = x->right;
    struct Node *T3 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T3;
    /** update height **/
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

struct Node *insert(struct Node *node, int data){
    if(node == NULL) return newNode(data);
    if(data < node->data) node->left = insert(node->left,data);
    else if(data > node->data) node->right = insert(node->right,data);
    else return node;

    /* Compute the new height of this ancestor node */
    node->height = 1 + max(height(node->left),height(node->right));

    int balance = getBalance(node);
    if(balance>1 && data<node->left->data) return rotateRight(node);
    if(balance<-1 && data>node->right->data )return rotateLeft(node);

    if(balance > 1 && data >node->left->data){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance < -1 && data < node ->right->data){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void menu(){
    printf("\nAVL Tree Menu\n");
    printf("1. Insert\n");
    printf("2. Inorder Traversal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    struct Node *root = NULL;
    int choice,data;
    do{
        menu();scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root,data);
                break;
            case 2:
                printf("\nInorder Traversal:");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Exitting...\n");
                break;
            default:
                printf("Invalid choice!\n");

        }
    }while(choice != 3);
    return 0;
}

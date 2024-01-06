//Linked list implementation of Stack

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();
void main(){
    int choice, value;
    printf("\n::Stack using Linked list::");
    while(1){
        printf("MENU\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();break;
            case 3:
                display();break;
            case 4:
                exit(0);
            default:
                printf("Wrong Selection!! Please try again\n");
        
        }
    }
}

void push(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc (sizeof(struct Node));
    newNode-> data = value;
    if(top==NULL)
        newNode -> next = NULL;
    else newNode -> next = top;
    top = newNode ;
    printf("Insertion Successful");
}

void pop(){
    if(top == NULL) printf("Stack is Empty");
    else{
        struct Node *temp=top;
        printf("Deleted element: %d",temp->data);
        top = temp -> next;
        free(temp);
    }
}

void display(){
    if(top == NULL) printf("Stack is Empty");
    else{
        struct Node *temp = top;
        while(temp -> next != NULL){
            printf("%d--->",temp-> data);
            temp= temp-> next;
        }
        printf("%d--->NULL", temp ->data);
    }
}
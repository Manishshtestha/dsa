//Basic Primitive operations of Circular queue

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct cQueue
{
int item[SIZE],front, rear;   
}cq;

void enQueue(int);
void deQueue();
void display();

void main(){
    int value,choice;
    cq.front = SIZE -1;
    cq.rear=SIZE-1;
    while(1){
        printf("\n\n***** MENU *****\n");
        printf("1. EnQueue\n2. DeQueue\n3. Display\n4. Exit");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4: exit(1);
            default:printf("\n Wrong selection!!! Try again !!!");
        }
    }
}

void enQueue(int d){
    if((cq.rear+1)%SIZE == cq.front){
        printf("\n Queue is full!!!\n");
    }
    else{
        cq.rear = (cq.rear+1)%SIZE;
        cq.item[cq.rear]=d;
    }
}

void deQueue(){
    if(cq.rear == cq.front){
        printf("\n Queue is empty \n");
    }else{
        cq.front = (cq.front+1)%SIZE;
        printf("Deleted item is:");
        printf("%d\n",cq.item[cq.front]);
    }
}

void display(){
    if(cq.rear == cq.front){
        printf("\n Queue is Empty.\n");
    }
    else{
        printf("Items in the Queue are:\n");
        for(int i=(cq.front+1)%SIZE;i!=(cq.rear+1)%SIZE;i=(i+1)%SIZE){
            printf("%d\t",cq.item[i]);     
        }
    }
}

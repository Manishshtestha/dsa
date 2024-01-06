// Implementation of Different Operations in Queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct lqueue
{
    int queue[SIZE], front, rear;
} q;

void enQueue(int);
void deQueue();
void display();

void main()
{
    int value, choice;
    q.front = 0;
    q.rear = -1;
    while (1)
    {
        printf("\n\tMENU");
        printf("\n\t1) En Queue");
        printf("\n\t2) De Queue");
        printf("\n\t3) Display");
        printf("\n\t4) Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to EnQueue:");
            scanf("%d", &value);
            enQueue(value);
            display();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Selection!! Try Again");
        }
    }
}

void enQueue(int value)
{
    if (q.rear == SIZE - 1)
        printf("Queue Overflow! enQueue Error");
    else
    {
        q.rear++;
        q.queue[q.rear] = value;
        printf("EnQueue Successful");
    }
}

void deQueue()
{
    if (q.rear < q.front)
        printf("Queue UnderFlow! deQueue Error");
    else
    {
        int i;
        printf("Deleted : %d", q.queue[q.front]);
        q.front++;
    }
}

void display()
{
    if (q.rear < q.front)
        printf("Queue UnderFlow");
    else
    {
        int i;
        printf("Queue Elements are:\n");
        for (i = q.front; i <= q.rear; i++)
        {
            printf("%d\t", q.queue[i]);
        }
    }
}
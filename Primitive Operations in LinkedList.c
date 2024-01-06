// Basic Primitive operations in linked list

#include <stdio.h>
#include <stdlib.h>

// void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node{
    int info;
    struct node *next;
};

struct node *start = NULL;
int main(){
    int choice;
    while (1){
        printf("\n1. Display\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at specified position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete from specified position\n");
        printf("8. Exit\n");
        printf("-----------------------------------------------------");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            display();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            exit(1);
        default:
            printf("\nWrong Choice\n");
            break;
        }
    }
    return 0;
}

void display(){
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n List is empty:\t");
        return;
    }
    else
    {
        ptr = start;
        printf("\n The List elements are:\t");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}

void insert_begin(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data value for the node: \t");
    scanf("%d", &temp->info);
    if (start == NULL){
        start = temp;
        temp->next = NULL;
    }else{
        temp->next = start;
        start = temp;
    }
}

void insert_end(){
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data value for the node:\t");
    scanf("%d", &temp->info);
    if (start == NULL){
        start = temp;
    }else{
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos(){
    struct node *temp, *ptr;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position to store the data;\t");
    scanf("%d", &pos);
    printf("\n Enter the data value of the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (pos == 0){
        temp->next = start;
        start = temp;
    }
    else{
        for (i = 1, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("\n Position not found:");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void delete_begin(){
    struct node *ptr;
    if(start == NULL){
        printf("\nList is Empty:\n");
        return;
    }else{
        ptr = start;
        start = start -> next;
        printf("The deleted element is %d",ptr->info);
        free(ptr);
    }
}
void delete_end(){
    struct node *ptr,*temp;
    if(start == NULL){
        printf("\nList is Empty:\n");
        return;
    }else if(start->next == NULL){
        ptr = start;
        start = NULL;
        printf("Deleted Element: %d\n ",ptr->info );
        free(ptr);
    }else{
        ptr = start;
        while(ptr->next!=NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\n The deleted element is %d",ptr->next);
        free(ptr);
    }
}
void delete_pos(){
    int i,pos;
    struct node *temp, *ptr;
    if(start == NULL){
        printf("\nThe List is Empty\n");
        exit(0);
    }
    else {
        printf("\nEnter the position of the node to be deleted:");
        scanf("%d",&pos);
        if(pos==0){
            ptr = start;
            start = start->next;
            printf("Element Deleted:%d \n",ptr->info);
            free(ptr);
        }
        else{
            ptr = start;
            for(i = 0;i<pos;i++){
                temp = ptr;
                ptr = ptr->next;
                if(ptr == NULL){
                    printf("Position not Found");
                    return;
                }
                temp -> next = ptr->next;
                printf("The deleted element is %d");
                free(ptr);
            }
        }
    }
}
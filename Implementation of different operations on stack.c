// Implementation of different operations of Stack

#include <stdio.h>
#define MAX 5

struct Stack{
    int stack[MAX], top;}st;

void push();
void pop();
void display();
void main(){
    int ch = 1;
    st.top = -1;
    while (1){
        printf("\n1. Push \n2. Pop \n3. Display\n4.Terminate\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thankyou for using");
                break;
            default:
                printf("Selection Error");
        }
    }
}

void push(){
    int num;
    if(st.top == MAX - 1){
        printf("\nStack Over flow");
        return;
    }
    else{
        printf("Enter Number:");
        scanf("%d",&num);
        st.top++;
        st.stack[st.top] = num;
        printf("Elements in the stacka are:\n");
        display();
    }
}

void pop(){
    if(st.top == -1){
        printf("Stack Underflow");
        return;
    }
    printf("Deleted element:%d",st.top);
    st.top--;
    printf("Elements in the stacka are:\n");
    display();
}

void display(){
    for(int i = st.top;i>=0;i--){
        printf("\n| %d |",st.stack[i]);
    }
    printf("\n");
}
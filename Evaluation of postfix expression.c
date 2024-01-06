//WAP to evaluate the given postfix expression
#include <stdio.h>
#include <string.h>

int main(){
    char S[80];
    int i, top = -1, n, x=0,y=0,stack[80];
    printf("\n Enter the valid Postfix notation:");
    scanf("%s",&S);
    n = strlen(S);
    printf("The value of the post fix notation:");
    for (i = 0; i<n ; i++) {
        switch(S[i]){
            case '+':
                y = stack[top];
                x = stack[top-1];
                top = top - 1;
                x = x + y;
                stack[top] = x;
                break;
            case '-':
                y = stack[top];
                x = stack[top-1];
                top = top - 1;
                x = x - y;
                stack[top] = x;
                break;
            case '*':
                y = stack[top];
                x = stack[top-1];
                top = top - 1;
                x = x * y;
                stack[top] = x;
                break;
            case '/':
                y = stack[top];
                x = stack[top-1];
                if(x == 0){
                    puts("Divide by zero");
                }else{
                    top = top - 1;
                    x = x / y;
                    stack[top] = x;
                }
                break;
            default:
                top++;
                if(S[i]>=48 && S[i]<=57)
                    x = S[i]-48;
                stack[top] = x;
                x = 0;
        }
    }
    printf("%d",stack[top]);
}
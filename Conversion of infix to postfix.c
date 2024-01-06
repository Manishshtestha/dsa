// WAP to convert infix expression to post fix expressiion

#include <stdio.h>
#include <string.h>
#define max 30

struct stack
{
    char item[max];
    int top;
} st;

void push(char symbol)
{
    if (st.top == max - 1)
    {
        printf("Stack Overflow");
        return;
    }
    st.item[++st.top] = symbol;
}

char pop()
{
    char i;
    if (st.top < 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    i = st.item[st.top];
    --st.top;
    return i;
}

int prec(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infix_to_postfix(char infix[])
{
    int length;
    static int index = 0, pos = 0;
    char symbol, temp;
    char postfix[50];
    length = strlen(infix);
    while (index < length)
    {
        symbol = infix[index];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[pos] = temp;
                pos++;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (prec(st.item[st.top]) >= prec(symbol))
            {
                temp = pop();
                postfix[pos] = temp;
                pos++;
            }
            push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;
        }
        index++;
    }
    while (st.top >= 0)
    {
        temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos++] = '\0';
    printf("\nThe PostFix Expression is : %s", postfix);
}

int main()
{
    char infix[max];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}

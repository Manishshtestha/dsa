//Recursive Function to find the fibonacci series
#include <stdio.h>

int fibo(int n){
    if(n<=1){
        return n;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}

void main(){
    int num;
    printf("Enter the number of terms:");
    scanf("%d",&num);
    for (int i = 0 ; i < num ; i++ ) {
        printf("%d + ",fibo(i));
    }
}
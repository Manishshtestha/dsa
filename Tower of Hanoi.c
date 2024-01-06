//Solution of Tower of Hanoi using Recursion
#include <stdio.h>                       
void TOH(int n,char x,char y, char z){
    if(n>0){
        TOH(n-1,x,z,y);
        printf("\n %c ==> %c",x,z);
        TOH(n-1,y,x,z);
    }
}

int main(){
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    TOH(n,'S','T','D');
}

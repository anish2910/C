#include<stdio.h>

void Increment(int *x){
    *x+=1;
    printf("Value of X from the function : %d",*x);
}

int main(){
    int x=10;
    Increment(&x);
    printf("\nValue of X from the main : %d",x);
}

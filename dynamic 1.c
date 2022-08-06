// creating first
#include<stdio.h>
int addn(int a,int b){
int s;
s=a+b;
return s;
}

//the foo
#include<stdio.h>
int addn(int a,int b);
int main(int argc,char *argv[]){
int t;
t=adddn(5,7);
printf("total=%d\n" t);
return 0;
}

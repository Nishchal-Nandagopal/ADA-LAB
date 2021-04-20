#include<stdio.h>
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return gcd(b,b%a);
}
int main(){
    int a,b;
    printf("Enter the two numbers\n");
    scanf("%d %d",&a,&b);
    printf("Gcd of two numbers is:%d",gcd(a,b));
}
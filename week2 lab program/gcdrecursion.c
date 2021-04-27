#include<stdio.h>

#include<stdlib.h>

int gcd(int a, int b)
{
if (b == 0)
return a;
int temp=a%b;
return gcd(b, temp);
}

int main()
{
	int a,b;
	printf("Enter two non-zero numbers\n");
    scanf("%d %d",&a,&b);
	printf("Gcd of two numbers is %d\n",gcd(a,b));
           
}
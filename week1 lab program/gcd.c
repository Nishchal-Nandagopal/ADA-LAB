#include <stdio.h>
#include <stdlib.h>
int i_gcd(int a, int b)       //iterative
{
int p, q;
while (b > 0)
{
p = a / b;
q = a - p * b;
a = b;
b = q;
}
return a;
}
int r_gcd(int a, int b)       //recursive
{
if (b == 0)
return a;
int m = a / b;
int n = a - m * b;
return r_gcd(b, n);
}
int main()
{
int a,b,choice;
printf("Enter two non-zero numbers\n");
scanf("%d %d",&a,&b);
printf("1)Iterative gcd\n2)Recursive gcd\n");
printf("Enter your choice:\t");
scanf("%d",&choice);
switch(choice)
{
    case 1:printf("Gcd of two numbers by iterative function is %d\n",i_gcd(a,b));
            break;
    case 2:printf("Gcd of two numbers by recursive function is %d\n",r_gcd(a,b));
            break;
    default:exit(0);
}
return 0;
}
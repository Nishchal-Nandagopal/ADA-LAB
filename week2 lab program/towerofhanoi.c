#include<stdio.h>


#include<stdlib.h>
void towers(int n,char s,char t,char d)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c \n",s,d);
		return;
	}
	towers(n-1,s,d,t);
	printf("move disk %d from %c to %c \n",n,s,d);
	towers(n-1,t,s,d);
}

int main()
{
	int n;
	printf("enter no of disks \n");
	scanf("%d",&n);
	towers(n,'S','T','D');
}
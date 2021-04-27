#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
int arr[100],n;

void selection_sort()
{
	int temp,small,pos;
	for(int i=0;i<n-1;i++)
	{
		small=arr[i];
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<small)
			{
				small=arr[j];
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
}
void display()
{
	for(int i=0;i<n;i++)
		printf("%d   ",arr[i]);
	printf("\n");
}


void main()
{
	
	printf("enter size of array \n");
	scanf("%d",&n);
	printf("enter  values into array  \n ");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("array before sorting :\n");
	display();
	selection_sort();
	printf("array after sorting :\n");
	display();
}
	
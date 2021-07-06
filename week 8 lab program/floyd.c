#include<stdio.h>

int a[10][10],d[10][10],n;
void floyds();
int min(int ,int);
int main()
{
	printf("Enter no of vertices:\t");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix :\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	floyds();
	printf("The Distance matrix is:\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
}

void floyds()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			d[i][j]=a[i][j];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
#include<stdio.h>

int a[10][10],p[10][10],n;
void warshall();
int main()
{
	printf("Enter no of vertices:\t");
	scanf("%d",&n);
	printf("Enter adjacency matrix :\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	warshall();
	printf("The path matrix is :\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
}
void warshall()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			p[i][j]=a[i][j];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((p[i][j]!=1)&&(p[i][k]==1)&&(p[k][j]==1))
					p[i][j]=1;
			}
		}
	}
}
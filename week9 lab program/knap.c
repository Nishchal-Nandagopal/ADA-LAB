#include<stdio.h>
int knapsack();
void object_sel();
int m,n,p[10],w[10],v[10][10],x[10];
int main()
{
    printf("enter no of objects\n");
    scanf("%d",&n);
    printf("enter weights of object \n");
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("enter profits of object \n");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("enter capacity of knapsack \n");
    scanf("%d",&m);
    int op_sol=knapsack();
    printf("OUTPUT:\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d  ",v[i][j]);
        printf("\n");
    }
    printf("Optimal  solution :  %d \n",op_sol);
    object_sel();
}
int max(int a,int b)
{
    return(a>b?a:b);
}

int knapsack()
{
    int i,j;
for( i=0;i<=n;i++)
{
    for( j=0;j<=m;j++)
    {
        if(i==0||j==0)
            v[i][j]=0;
        else if(w[i]>j)
            v[i][j]=v[i-1][j];
        else
            v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
    }
}
return(v[i-1][j-1]);
}
void object_sel()
{
    int i=n,j=m;
    while(i!=0&&j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    printf("object selected :\n");
    for(int i=1;i<=n;i++)
    {
        if(x[i]==1)
            printf("%d \n",i);
    }
}
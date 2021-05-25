#include<stdio.h>
void dfs(int);
int a[10][10],vis[10],n,flag=0;
int main()
{
   int i,j,src;
   printf("Enter number of vertices:: \n");
   scanf("%d",&n);
   printf("Enter adjacency matrix:: \n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d", &a[i][j]);
     }
  }
for(i=1;i<=n;i++)
vis[i]=0;
printf("Enter source vertex\n");
scanf("%d",&src);

dfs(src);

for(i=1;i<=n;i++)
{
    if(vis[i] == 0)
    {
        printf("Graph not connected\n");
        flag=1;
        break;
    }
}
if(flag==0)
printf("Graph connected\n");
}
void dfs(int v)
{
int i;
vis[v]=1;

   for(i=1;i<=n;i++)
   {
        if(a[v][i]==1 && vis[i]==0)
       dfs(i);
   }
}
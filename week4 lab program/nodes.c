#include<stdio.h>
void dfs(int);
int a[10][10],vis[10],n;
int main()
{
   int i,j,src;
   printf("Enter number of vertices: \t");
   scanf("%d",&n);
   printf("Enter adjacency matrix: \n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d", &a[i][j]);
     }
  }
for(i=1;i<=n;i++)
vis[i]=0;
printf("Enter source vertex:\t");
scanf("%d",&src);
printf("Nodes reachable from vertex %d:\t",src);
dfs(src);

}
void dfs(int v)
{
int i;
vis[v]=1;
printf("%d\t",v);
   for(i=1;i<=n;i++)
   {
        if(a[v][i]==1 && vis[i]==0)
       dfs(i);
   }
}
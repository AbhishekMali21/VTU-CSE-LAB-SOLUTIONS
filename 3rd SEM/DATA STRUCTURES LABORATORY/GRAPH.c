#include <stdio.h>
#include <stdlib.h>
int a[20][20],q[20],visited[20],reach[20],n,f=0,r=-1,count=0;
void bfs(int v)
{
    int i;
    for(i=1;i<=n;i++)
      if(a[v][i]&&!visited[i])
      {
        visited[i]=1;
        q[++r]=i;
      }
      if(f<=r)
        bfs(q[f++]);
}
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
      if(a[v][i]&&!reach[i])
      {
        printf("%d->%d\n",v,i);
        count++;
        dfs(i);
      }
}
int main()
{
    int v,ch,i,j;
    printf("\nenter no. of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      reach[i]=visited[i]=q[i]=0;
    printf("\nEnter graph data in matrix form:\n");
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    printf("\n1.BFS\n2.DFS\n3.Exit\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter vertex:");
               scanf("%d",&v);
               bfs(v);
               printf("\nThe nodes that are reacheble from %d are:\n",v);
               for(i=1;i<=n;i++)
                  if(visited[i])
                    printf("%d ",i);
               break;
        case 2:dfs(1);
               if(count==n-1)
                  printf("\ngraph is connected");
               else
                  printf("\ngraph is not connected");
               break;
        case 3:exit(0);
        default:printf("\nInvalid choice");
    }
    return 0;
}
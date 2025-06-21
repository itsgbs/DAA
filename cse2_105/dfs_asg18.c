#include<stdio.h>
#include<stdlib.h>
int g[10][10],vis[20],v1,n;
int dfs(int v)
{
	int j;
	vis[v]=1;
	printf("\t%d->",v);
	for(j=0;j<n;j++)
	{
		if(!vis[j]&&g[v][j])
		{
			dfs(j);
		}
	}
}
int main()
{
	int i,j;
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("Enter the matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf(" the matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%d",g[i][j]);
		}
		printf("\n\n");
	}
	for(i=0;i<n;i++)
	vis[i]=0;
	printf("\nedges:\n");
	// printf("\nEnter the source vertex:");
	// scanf("%d",&v1);
	dfs(0);
	return 0;
	
}
/*
0 1 0 1 1 0 0
1 0 1 0 1 0 0
0 1 0 0 1 1 1
1 0 0 0 1 0 0
1 1 1 1 0 1 0
0 0 1 0 1 0 1
0 0 1 0 0 1 0
*/


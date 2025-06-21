#include<stdio.h>
#include<stdlib.h>
#define INF 99999
int mincost=0,g[20][20],visited[20];
int prims(int n)
{
	int min,i,j,k,v1,v2;
	for(i=0;i<n;i++)
	visited[i]=0;
	visited[0]=1;
	for(k=1;k<n;k++)
	{
		min=INF;
		for(i=0;i<n;i++)
		{
			if(visited[i])
			{
				for(j=0;j<n;j++)
				{
					if(!visited[j]&&g[i][j]<min)
					{
						min=g[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		printf("\nedge = %d=(%d-%d)=%d\n",k,v1,v2,min);
		visited[v2]=1;
		mincost=mincost+min;
	}
	return mincost;
}

int main()
{
	int i,j,n;
	printf("enter the number of vertex:");
	scanf("%d",&n);
	printf("\nenter the adjecency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
			if(g[i][j]==0)
				g[i][j]=INF;
		}
	}
	printf("\nthe minimal edges are:\n");
	mincost=prims(n);
	printf("mst of prims:%d",mincost);
	return 0;
}

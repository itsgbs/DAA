#include<stdio.h>
#define INF 99999
int n,cost[10][10],dist[10],pred[10],visit[10];
void djk(int s)
{
	int count,min,u,i,v;
	for(i=1;i<=n;i++)
	{
		dist[i]=cost[s][i];
		pred[i]=s;
		visit[i]=0;
	}
	dist[s]=0;
	visit[s]=1;
	count=2;
	while(count<=n)
	{
		min=INF;
		for(i=1;i<=n;i++)
		{
			if(dist[i]<min&&visit[i]!=1)
			{
				min=dist[i];
				v=i;
			}
		}
		visit[v]=1;
		count++;
		for(i=1;i<=n;i++)
		{
			if(dist[i]>dist[v]+cost[v][i])
			{
				dist[i]=dist[v]+cost[v][i];
			}
		}
	}
}

int main()
{
	int i,j,start;
	printf("\nenter the number of vertex:");
	scanf("%d",&n);
	printf("\nenter adj matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=INF;
			
		}
	}
	printf("\nenter the starting vertex:");
	scanf("%d",&start);
	djk(start);
	for(i=1;i<=n;i++)
	{
		if(i!=start)
		printf("\n %d->%d=%d\n",start,i,dist[i]);
	}
	return 0;
}


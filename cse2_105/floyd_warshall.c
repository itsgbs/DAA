#include<stdio.h>
#define INF 99
int g[10][10],dist[10][10],p[10][10];
void warshall(int n)
{
	int i,j,k;
	
	for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				dist[i][j]=g[i][j];
				p[i][j]=-1;
				}

	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				//dist[i][j]=g[i][k]+g[k][j];
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					p[i][j]=k;
				}
				//if(i!=j&&g[i][j]==0)
			}
		}
	}
}

int main()
{
	int i,j,k,n;
	printf("\nenter the number of vertex:");
	scanf("%d",&n);
	printf("\nenter adj matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
			if(i!=j && g[i][j]==0)
			g[i][j]=INF;
			
		}
	}
warshall(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
	//	if(i!=j&&g[i][j]==0)
		if(p[i][j]!=1)
			printf("\n (%d->%d->%d)=%d\n",i,p[i][j],j,dist[i][j]);
		else
			printf("\n (%d->%d)=%d\n",i,j,dist[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		printf("D matrix\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
			printf("%d\t",dist[i][j]);
			}
		printf("\n");
	}
	printf("p matrix\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d\t",p[i][j]);
			}
		printf("\n");
		}
	}


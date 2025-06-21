#include<stdio.h>
#include<stdlib.h>
int n,g[10][10],visited[10],queue[10]={0},rear=-1,front=-1;
void bfs(int v)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!visited[i]&&g[v][i]) //checking whether the vertex i is already visited and also is there edge between source vertex v and i 
		{
			if(front==-1)
			front=0;
			queue[++rear]=i;
			visited[i]=1;
			printf("%d ",i);
		}
	}
	if(front<=rear) // base case if front > rear then stop 
	bfs(queue[front++]);
	
}
int main()
{
	int s,i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("Adjacency Matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	visited[i]=0;
	printf("Enter start vertex:");
	scanf("%d",&s);
	printf("The bfs traversal = ");
	printf("%d ",s);
	visited[s]=1;
	bfs(s);
}
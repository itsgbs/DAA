#include<stdio.h>
int g[10][10],m,n,x[10]={0};
void mColoring(int k)
{ 
int i;
	do
	{
		NextValue(k);
		if(x[k]==0)
		{
			return;
		}
		if(k==n)
		{
			for(i=1;i<=n;i++)
		{
		
		printf("\t%d ",x[i]);
			}
		}
		else{
		
		mColoring(k+1);
	}
	}
	while(k<n+1);
}

int NextValue(int k)
{
	int i,j;
	while(1)
	{
	
	x[k]=(x[k]+1)%(m+1);
	if(x[k]==0)
	{
		return;
	}
	for(j=1;j<=n;j++)
	{
		if((g[k][j]!=0)&&(x[k]==x[j]))
		break;
	}
	if(j==n+1)
	{
		return;
	}
}
}
int main()
{
	printf("enter the vertices:");
	scanf("%d",&n);
	printf("enter the color:");
	scanf("%d",&m);
	mColoring(1);
}

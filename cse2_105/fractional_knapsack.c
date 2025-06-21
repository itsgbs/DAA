#include<stdio.h>
float p[50],w[50],r[50],x[50],temp;
void sort(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(r[j]<r[j+1])
			{
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			
			}
		}
	}
}

void knapsack(float m,int n)
{
	float u;
	int i;
	u=m;
	for(i=0;i<n;i++)
	{
		x[i]=0.0;
	}
	for(i=0;i<n;i++)
	{
		if(w[i]>u)
		break;
		else
		{
		
		x[i]=1.0;
		u=u-w[i];
	}
}
	if(i<=n)
		x[i]=u/w[i];
	
}

int main()
{
	int i,n,m;
	float sum=0.0;
	printf("Enter the knapsack capacity:");
	scanf("%d",&m);
	printf("\nEnter the number of items:");
	scanf("%d",&n);
	printf("Enter the weights and profit:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&w[i],&p[i]);
		r[i]=p[i]/w[i];
	}
	sort(n);
	printf("\nElemnts after sorting:\n");
	printf("\n sl.no.\tWeight\tProfit\tratio\n");
	for(i=0;i<n;i++)
	{
		printf(" \n%d %f %f %f\n",i+1,w[i],p[i],r[i]);
	}
	knapsack(m,n);
	printf("\n The solution vector is:\n");
	for(i=0;i<n;i++)
	{
		printf("%f\t",x[i]);
		sum+=x[i]*p[i];
	}
	printf("\nMaximum Profit:%f",sum);
	return 0;
}
/*
18 25
15 24
10 15
*/


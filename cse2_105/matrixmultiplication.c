#include<stdio.h>
#include<limits.h>
#define inf 99999
int p[10],m[10][10],s[10][10];
void matrixchain(int n)
{
	int i,j,l,k,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;
		for(l=2;l<=n;l++)
		{
			for(i=1;i<=n-l+1;i++)
			{
				j=i+l-1;
				m[i][j]=inf;
				for(k=i;k<=j-1;k++)
				{
					q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
					if(q<m[i][j])
					{
						m[i][j]=q;
						s[i][j]=k;
					}
				}
			}
		}
	printf("%d",m[1][n]);
	printf("%d",s[1][n]);
}

void print_optimal_parens(int i,int j)
{
	if(i==j)
	printf("A%d",i);
	else
	{
		printf("(");
		print_optimal_parens(i,s[i][j]);
		print_optimal_parens(s[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int num,i,j;
	printf("enter the value of num:");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		scanf("%d",&p[i]);
		matrixchain(num-1);
		printf("\ntable\n");
		for(i=1;i<num;i++)
		{
		 for(j=1;j<num;j++)
		 printf("%d ",m[i][j]);	
		 printf("\n");
		}
		printf("\n");
		for(i=1;i<num;i++)
		{
		 for(j=1;j<num;j++)
		 printf("%d ",s[i][j]);	
		 printf("\n");
		}
		printf("\n");
		print_optimal_parens(1,num-1);
}

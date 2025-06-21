#include<stdio.h>
#include<math.h>
int x[20],m=1;
int Place(int ,int );
void Nqueen(int k,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if (Place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				printf("\nSolution %d : \n",m);
				m++;
				for(i=1;i<=n;i++)
				{
					printf("%d ",x[i]);
				}
				printf("\n");
				for(i=1;i<=n;i++)
				{
					printf("-");
					for(j=1;j<=n;j++)
					{
						printf("-----");
					}
					printf("\n");
					printf("|");
					for(j=1;j<=n;j++)
					{
						if(x[i]==j)
						{
							printf(" Q%d |",i);
						}
						else
						{
							printf("    |");
						}
					}
					printf("\n");
				}
				printf("-");
				for(j=1;j<=n;j++)
				{
					printf("-----");
				}
				printf("\n");
			}
			else Nqueen(k+1,n);
		}
	}
}

int Place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		return 0;
	}
	return 1;
}

int main()
{
	int n,i,j;
	printf("Enter the index of chess:");
	scanf("%d",&n);
	Nqueen(1,n);
	
}
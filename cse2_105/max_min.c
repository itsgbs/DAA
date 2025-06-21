#include<stdio.h>
int a[100];
int max_min(int i,int j,int *max,int *min)
{
	int max1,min1,mid;
	if (i==j)
	{
		*max=*min=a[i];
	}
	else
	{
		if(i==j-1)
		{
			if(a[i]<a[j])
			{
				*max=a[j];
				*min=a[i];
			}
			else
			{
				*max=a[i];
				*min=a[j];
			}
		}
		else
		{
			mid=(i+j)/2;
			max_min(i,mid,max,min);
			max1=*max;
			min1=*min;
			max_min(mid+1,j,max,min);
			if(*max<max1)
			*max=max1;
			if(*min>min1)
			*min=min1;
		}
	}
}

int main()
{
	int i,num,max,min;
	printf("\n Enter the size:");
	scanf("%d",&num);
	printf("\nEnter the elements:\n");
	for(i=0;i<num;i++)
	{
		printf("\nindex %d:\t",i);
		scanf("%d",&a[i]);
	}
	
	max_min(0,num-1,&max,&min);
	printf("\nMaximum:%d",max);
	printf("\nMinimum:%d",min);
	return 0;
}

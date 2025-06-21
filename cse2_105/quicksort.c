#include<stdio.h>
int a[50];
int partition(int p, int r)
{
    int i,j,x,t;
    x=a[p];
    i=p;
    j=r;
    while (i<j)
    {
    while (a[i]<=x)
        i++;
    while (a[j]>x)
        j--;
    if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[j];
    a[j]=a[p];
    a[p]=t;
    return j;
}
void quicksort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
        
    }
}
int main()
{
   int n,i;
   printf("enter the value of n:");
   scanf("%d",&n);
   for (i=0;i<n;i++)
   {
       printf("%d:",i);
   scanf("%d",&a[i]); 
    }
    quicksort(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

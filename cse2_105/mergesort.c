#include<stdio.h>
int a[50];
void merge(int low,int mid, int high)
    {
       int h= low , i=low, j=mid+1;
       int b[50];
       while((h<=mid)&&(j<=high))
       {
           if (a[h]<a[j])
           {
               b[i++]=a[h++];
           }
           else
                b[i++]=a[j++];
       }
       while(h<=mid)
        b[i++]=a[h++];
       while(j<=high)
        b[i++]=a[j++];
       for (i=low;i<=high;i++)
       {
       a[i]=b[i];
        }
    }

void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
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
    mergesort(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

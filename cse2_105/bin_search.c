#include<stdio.h>
#include<stdlib.h>
int a[50],n,item;
int binary_search(int l, int u)
{ 
    int mid;
    printf("\nenter the no. to be searched:");
    scanf("%d",&item);
    if(l<=u)
    {
        mid=(l+u)/2;
        if(item==a[mid])
        return mid;
        else if(item<a[mid])
        u=mid-1;
    else
        l=mid+1;
}
return -1;
}

int main()
{
    int l,u,i,res;
    printf("\nenter the size of the array:");
    scanf("%d",&n);
    l=0,u=n-1;
    printf("\nenter %d elemnts in sorted manner:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n array elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    res=binary_search(l,u);
    if (res==-1)
    printf("\nitem not found");
    else
    printf("\nitem found at %d",res+1);
    return 0;
}




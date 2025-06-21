#include<stdio.h>
#include<stdlib.h>
int a[20],n,item;
int binary_search(int l, int u)
{ 
    int mid;
    
    if(l<=u)
    {
        mid=(l+u)/2;
        if(item==a[mid])
        return mid;
        else if(item<a[mid])
        return binary_search(l,mid-1);
    else
    return binary_search(mid+1,u);
}
return -1;
}

int main()
{
    int l,u,i,res;
    printf("\nenter the size of the array:");
    scanf("%d",&n);
    l=0,u=n-1;
    printf("\nenter %d elements in sorted manner:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n array elements are\t:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n enter the no. to be searched:");
    scanf("%d",&item);
    res=binary_search(l,u);
    if (res==-1)
    printf("\nitem not found");
    else
    printf("\nitem found at %d",res+1);
    return 0;
}




#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
        return -1;
}
int linearSearch(int arr[], int l,int r, int x)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return linearSearch(arr, l + 1,r - 1, x);
}
int main()
{
    int a[100],n,x,s,t,choice;
    printf("Enter the number of elements:\t");
    scanf("%d",&n);
        for(;;)
        {
    printf("1)LINEAR SEARCH\n2)BINARY SEARCH\n3)EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched:\t");
    scanf("%d",&x);
        s=linearSearch(a,0,n-1,x);
            if(s==-1)
                 printf("Element not found.\n");
                 else
                    printf("Element found at position %d.\n",s+1);
                    break;
        case 2:printf("Enter the elements in increasing order:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched:\t");
    scanf("%d",&x);
        t=binarySearch(a,0,n-1,x);
            if(t==-1)
                 printf("Element not found.\n");
                 else
                    printf("Element found at position %d.\n",t+1);
                    break;
        default:exit(0);
    }
        }
    return 0;
}
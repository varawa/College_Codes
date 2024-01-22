#include<stdio.h>
#include<stdlib.h>
int search_element(int x , int arr[] ,int n);
void main()
{
    int z,n,x,arr[100],i;
    printf("No. of elements in array:\n");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        arr[i]=rand()%100;
    }
    printf("The array is:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nElement to search :\n");
    scanf("%d",&x);
    z=search_element(x,arr,n);
    if(z==1)
    printf("Element not found.");
    else
    printf("Element found at %d.",z);
}
int search_element(int x , int arr[] , int n)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
        if(arr[i]==x)
        {
          return i;
          exit;
        }
    }
    return 1;
}
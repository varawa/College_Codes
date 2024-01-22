#include<stdio.h>
#include<stdlib.h>
void main()
{
    int arr[100],i,j,lef,rgt,n,x,m,k,l,temp=0;
    printf("Enter the no. of elements:\n");
    scanf("%d",&n);
    
    for(i=0;i<=n-1;i++) //Entering array elements.
    {
       arr[i]=rand()%100;
    }
    printf("Array before Sorting:\n");
    for(i=0;i<=n-1;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");

    for(k=0;k<n-1;k++) //Bubble sort to place array increasing order.
    {
        for(l=0;l<n-k-1;l++)
        {
            if(arr[l]>arr[l+1])
            {
            temp=arr[l];
            arr[l]=arr[l+1];
            arr[l+1]=temp;
            }
        }
    }
    printf("Array after sorting :\n");
    for(i=0;i<=n-1;i++) //Array after sorting.
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("The number to be searched:\n");
    scanf("%d",&x);
    lef=0; //Declaring left and right end.
    rgt=n-1;
    for(j=0;j<=n-1;j++) //Binary search .
    {
       m=(lef+rgt)/2;//Middle term of array.
       if(x==arr[m]) 
       {
       printf("The term %d is found at index %d .",x,m);
       return;
       }
       if(x>arr[m])
        lef=m+1;   //To define new left end.
       if(x<arr[m])
        rgt=m-1;   //To define new right end.
    }
     printf("Element not found.");
}

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main()
{
    int a[100],n,i,j,k,m;
    int count=0;
    bool swap;
    printf("No. of elements in array :");
    scanf("%d",&n);
    printf("Enter Elements:");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=0;k<n-1;k++)
    {
        swap=false;
        for(j=0;j<n-k-1;j++)
        {
            if(a[j]>a[j+1])
            {
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swap=true;
            }
          count++;  
        }
        if(swap==false)
        {
            break;
        }
    }
    for(i=0;i<=n-1;i++)
    {
        printf("%d \n",a[i]);
    }
    printf("  %d",count);
    return 0;
}
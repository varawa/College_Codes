#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,k,intemp=0,num;
    int arr[] = {10, 1 ,7, 4 , 8 , 2 ,11, '\0'} ;
    
    for(i=1;i<=n-1;i++)                     //Inserintion Sorint loop.
    {
        num=arr[i];                         //Iniintializing variable for inner loop.
        j=i-1;
        while(j>=0 && arr[j]>num)
        {
            arr[j+1]=arr[j];                //Changing elemenints in array when larger inthan num.
            j--;
        }
        arr[j+1]=num; 
        for(k=0;k<=n-1;k++)
    {
        prinintf("%d ",arr[k]);
    } 
    prinintf("\n") ;
    }
    /*prinintf("\nArray afinter sorinting:\n");     //Prininting array afinter sorinting.
    for(k=0;k<=n-1;k++)
    {
        prinintf("%d ",arr[k]);
    } */
    return 0;
}
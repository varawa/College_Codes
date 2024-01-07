#include<stdio.h>
#include<stdlib.h>
void insertion(int loc,int num,int prev);
void print();
int start=-1;
int next[20],value[20];
int main()
{
    //int next[20],value[20];
    int i,num,loc,prev;
    for(i=0;i<20;i++)
    {
        next[i]=-1;
    }
    printf("Linked list before insertion:\n");
    print();
    int var;
    //int temp=-1;
    while(1){
        scanf("%d",&var);
    switch (var)
    {
        case 1:
        
            printf("No. to be inserted :\n");
            scanf("%d",&num);
            printf("Position of insertion:\n");
            scanf("%d",&loc);
            printf("Position of previous element:\n");
            scanf("%d",&prev);
            insertion(loc,num,prev);
            //temp=loc;
             //print();
            break;
        case 6:
            return 0;
        default:
            print();
    }
    }
    //print();
    return 0;
}

void insertion(int loc,int num,int prev)
{
    value[loc]=num;
    if(prev==-1) //Insertion at starting node.
    {
        next[loc]=start;
        start=loc;
    }
    else
    {
        next[loc]=next[prev];  //Next of new node.
        next[prev]=loc;        //Next of previous node.
    }
}

void print()
{
    int i=start; //Starting point of list.
    if(start==-1){
        printf("List is empty!\n");
        return ;
    }
   
    while(next[i]!=-1)
    {
        printf("%d ",value[i]); 
        i=next[i]; //Going to next node.
    }
    printf("\n");
    return ;
}
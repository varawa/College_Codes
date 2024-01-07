#include<stdio.h>
#include<stdlib.h>
void deletion(int del);
int search(int src);
void create(int n);
void print();
void insertion(int y,int loc);

struct node
{
int value;
struct node*next;
};

struct node*head=NULL;
int main()
{
    int n,i,x;
    printf("Number of elements in linked list:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Element number %d is :\n",i);
        scanf("%d",&x);
        create(x);
    }
    printf("\nLinked list before any oprations:\n");
    print();
    int var,num,check,loc;
    while(1){
        printf("\nTo perform :\n\nSearch enter 1.\n\nInsertion enter 2.\n\nDeletion enter 3.\n\nEnter 4 to close program.\n\n");
        scanf("%d",&var);
        switch (var){
            case 1:
                printf("\nNumber to be searched:\n");
                scanf("%d",&num);
                check=search(num);
                if(check==-1){
                    printf("\nNumber not found.\n");
                }
                else{
                    printf("\nNumber found at %d.\n",check);

                } 
                break;
            case 2:
                printf("\nPlease enter number to be inserted \n");
                scanf("%d",&num);
                printf("\nPlease enter location where number inserted\n");
                scanf("%d",&loc);
                insertion(num,loc);
                printf("\nLinked list after insertion:\n");
                print();
                break;
            case 3:
                printf("\nPlease enter number to be deleted. \n");
                scanf("%d",&num);
                deletion(num);
                printf("\nLinked list after deletion:\n");
                print();
                break;
            case 4:
                return 0;
        }
    }
return 0;
}

void create(int n)
{
    struct node *temp;
    temp=head;
    if(head==NULL){  //If list is empty.
        head=(struct node*)malloc(sizeof(struct node));
        head->value=n;
        head->next=NULL;
    }
    else
    {
        while(temp->next!=NULL) //Reaching the last node.
        {
            temp=temp->next;
        }
        struct node *t=(struct node*)malloc(sizeof(struct node));
        t->value=n; //Adding node at last location.
        t->next=NULL;
        temp->next=t; 
    }
}

void print() //Printing the linked list.
{
    if(head==NULL){  
        printf("Empty!\n");
    }
    else{
        struct node* temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d  ",temp->value);
            temp=temp->next;
        }
            printf("\n");
    }
}

void insertion(int y,int loc)
{
    int i=0;
    struct node*new; 
    new=(struct node*)malloc(sizeof(struct node));   
    if(loc==0){   //Insertion at location 0.
        new->value=y;
        new->next=head;
        head=new;
    }
    // To insert on locations other than 0.
    struct node* temp;  
        temp=head;
    while(i<loc-1)  
    {
        if(temp==NULL)
        {
            printf("Location is greater than list size.\n");
            return;
        }
        temp=temp->next;
        i++;
    }
    printf("\n");
    new->value=y;
    new->next=temp->next;
    temp->next=new;
}

int search(int src)  //To search an element.
{
    int count=-1;
        struct node* temp;
        temp=head;
        while(temp!=NULL)
        {
            count++;
            if(temp->value==src){
                    //printf("Found at location: %d .",count);
                    return count;
            }
            temp=temp->next;
        }
    return -1;
}

void deletion(int del)
{
    //struct node*temp=(struct node*)malloc(sizeof(struct node));
    
    if(head->value==del)
    {
        head=head->next;
        return ;
    }
    else{
        struct node*temp=head;
        //printf("before while %d\n",temp->value);
        while(temp->next!=NULL){
            if((temp->next)->value==del){
                temp->next=(temp->next)->next;
                return ;
            }
            //printf("temp after if %d\n",temp->value);
            temp=temp->next;
        }
        printf("Number not found!\n");
        return ;
    }
}
#include<iostream>
using namespace std;
int top=-1;
char str[100];
int push(char add);
void pop();
void search(char ser);
void display();
void reverse();
int main()
{
    int n,x;
    cout<<"Enter the number of elements in stack:\n"<<endl;
    cin>>n;
    while(1)
    {
        cout<<"Enter 1 to push .\n\nEnter 2 to pop .\n\nEnter 3 to search .\n\nEnter 4 to reverse .\n\nEnter 5 to display .\n\nEnter 6 to end .\n\n"<<endl;
        cin>>x;
        
    }    

}

int push(char add)
{
    str[top+1]=add;
    top++;
    return top;
}

void pop()
{
    top=top-1;
}

void search(char ser)
{
    int i;
    for(i=0;i<=top;i++)
    {
        if(str[i]==ser)
        {
            cout<<"Element found at index : "<<i<<endl;
            return;
        }
    }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<str[i] <<endl;
    }
}

void reverse()
{
    int temp=0;
    temp=str[top];
    top=top-1;
    cout<<temp <<endl;
}
#include<iostream>
using namespace std;
int arr[100],top=-1,n,add,ser,temp=0;
int push(int add);
int pop();
int search(int ser);
int reverse();
void display();
int main()
{
    int x;

    //Number of elements in stack.

    cout<< "\nEnter the number of elements :\n"<<endl;
    cin>>n;
    cout<<"\n"<<endl;
    while(1)
    {
        cout<<"Press 1 to push.\n\nPress 2 to pop.\n\nPress 3 to search.\n\nPress 4 to reverse.\n\nPress 5 to display.\n\nPress 6 to end.\n"<<endl;
        cin>>x;
        cout<<"\n"<<endl;
        switch(x)
        {
            case 1:
                //cout<<top<<endl;
                if(top>=n-1)
                {
                    cout<<"Stack Overflow!\n"<<endl;
                }
                else
                {
                cout<<"Number to be added:\n"<<endl;
                cin>>add;
                push(add);
                cout<<"\n"<<endl;
                }
                break;
            case 2:
                pop();
                cout<<"\n"<<endl;
                break;
            case 3:
                cout<<"Number to be searched:\n"<<endl;
                cin>>ser;
                search(ser);
                cout<<"\n"<<endl;
                break;
            case 4:
                reverse();
                break;
            case 5:
                display();
                cout<<"\n"<<endl;
                break;
            case 6:

                //To end while loop.

                return 0;
            default:
                cout<<"Error!\n"<<endl;
                break;
        }
    }
    return 0;
}

//To add a new element in stack.

int push(int add)
{
    arr[top+1]=add;
    top++;
    return 0;
}

//To delete the last added element in stack.
//Last in first out (LIFO).

int pop()
{
    top=top-1;
    return temp;
}

//To reverse the stack.

int reverse()
{
    while(top!=-1)
    {

        //To store the last added element in temp.

        temp=arr[top];  
        top=top-1;
        cout<<temp<<endl;
    }
    return 0;
}

//To display the stack.

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        cout<<arr[i] <<endl;
    }
}

//To search an element in stack.

int search(int ser)
{
    int i;
    for(i=0;i<=top;i++)
    {
        if(arr[i]==ser)
        {
            cout<<"\nElement found at index :"<<i <<".\n\n"<<endl;
            break;
        }
    }
    return 0;
}

#include<iostream>

using namespace std;
class circular_queue
{
    private:
        
        int size ;
        int front ;
        int rear ;
        int q[] ;
        
    public:

        circular_queue(){

        }

        circular_queue(int sz )
        {
            int i ;
            size = sz ;
            front = -1 ;
            rear = -1 ;
            for(i = 0 ; i < size ; i++){
                q[i] = -1 ;
            }
        }
        
        void enqueue(int data )
        {
            if(front == -1)
            {
                front++ ;
                rear++ ;
                q[rear] = data ;
            }
            else if( front == 0 && rear == size-1 ){
                cout<<"Queue is full ."<<endl;
            }
            else 
            {
                rear = ( rear + 1 ) % size ;
                q[rear] = data ; 
            }
        }
        void dequeue()
        {
            int y ;
            if(front == -1)
                cout<<"Queue is empty ."<<endl;
            else if(front == rear)
            {
                y = q[front] ;
                q[front] = -1 ;
                front = -1 ;
                rear = -1 ;
                cout<<" Deleted element ."<<endl;
            }
            else 
            {
                y = q[front] ;
                q[front] = -1 ;
                front = (front + 1) % size ;
                cout<<y<<"Deleted element ."<<endl;
            }
        }
        void display()
        {
            int i ;
            i = front ;
            if(front == -1)
                cout<<"Queue is empty ."<<endl;
            else
            { 
                i = front ;
                cout<<"Front= "<<front<<endl ;
                cout<<"Rear= "<<rear<<endl ;
                cout<<"Elements of the circular queue ."<<endl ;
                int count = 0 ;
                while(i < size && count != size)
                {
                    if(q[i] != -1)
                    cout<<q[i]<<endl ;
                    count++ ;
                    i=(i+1) % size ;
                }
            }
        }
};

int main()
{
    circular_queue q(1) ;
    int data , choice ;
    while(1){ 
        
        cout<<"Enter 1 for enqueue ."<<endl<<"Enter 2 for dequeue ."<<endl<<"Enter 3 for display ."<<endl<<"Enter 4 for exit ."<<endl ;
        cin>>choice ;
        switch(choice){
            case 1 :
                cout<<"Element to be inserted :"<<endl ;
                cin>>data ;
                q.enqueue(data) ;
                break ;
            
            case 2 :
                q.dequeue() ;
                break ;
            
            case 3 :
                q.display() ;
                break ;
            
            case 4 :
                return 0 ;
        }
    }
}
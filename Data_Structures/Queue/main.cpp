#include <iostream>
#define MAX 30
using namespace std;
template <class T>
class Queue
{
private:
    T arr[MAX];
    int front,rear,size;
public:
    Queue()
    {
        arr[MAX]= {0};
        front=rear=-1;
    }
    Queue(int s)
    {
        size=s;
        front=rear=-1;
    }
    void enQ(T value)
    {
        if(((front==0)&&rear==size-1)||(front==rear+1))
        {
            cout<<"\n\n Queue is full :: ";
            return ;
        }
        if(front ==-1||rear==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear=(rear+1)%size;
        arr[rear]=value;
    }
    T deQ()
    {
        T value;
        if(front==-1)
        {
            cout<<"\n\n Queue is Empty ! ";
        }
        else
        {
            value= arr[front++];
            if(front=rear)
                front=rear=-1;

        }
        return value;
    }
    void display()
    {
        cout<<"\n\n Queue is :: ";
        for(int i=front; i<=rear; i++)
        {
            cout<<" "<<arr[i];
        }
    }
};
int main()
{

    int s;
    cout<<"\n\n Enter the size of Queue :: ";
    cin>>s;
     Queue<int> q(s);
    int choice,value;
    do

    {
        cout<<"\n\n\t MENU ";
        cout<<"\n\n 1. Enqueue a element .";
        cout<<"\n\n 2. Dequeue a element .";
        cout<<"\n\n 3. Display Queue .";
        cout<<"\n\n 4. Exit .";
        cout<<"\n\n\n Enter your choice :: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\n\n Enter the element :: ";
            cin >>value;
            q.enQ(value);
            break;
        case 2:
            cout<<"\n\n Value is :: "<<q.deQ();
            break;
        case 3:
            q.display();
            break;
        case 4:
            break;
        default:
            cout<<"\n\n WRONG CHOICE !!";
        }
    }
    while(choice<4);
    return 0;
}

using namespace std;

template <class T>
class CircularLinkedQueue
{
public:

    class node
    {
    public:
        T info;
        node *next;
    }*rear;

    CircularLinkedQueue()
    {
        rear=NULL;
    }
    void enqueue(T info);
    T dequeue();
    void display();
    bool isEmpty();

};
template <class T>
void CircularLinkedQueue<T> :: enqueue(T info)
{
    node *temp= new node;
    temp->info=info;
    temp->next=NULL;
    if(rear==NULL)
    {
           rear=temp;
           rear->next=rear;
    }
    else
    {
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
    }
}

template <class T>
T CircularLinkedQueue<T> :: dequeue()
{
    node* temp=rear->next;
    if(rear->next==rear)
    {
        rear=NULL;
    }
    else
    {
        rear->next=temp->next;
    }
    T info= temp->info;
    delete temp;
    return info;
}
template <class T>
bool CircularLinkedQueue<T> :: isEmpty()
{
    if(rear==NULL)
    {
        return true;
    }
    return false;
}
template <class T>

void CircularLinkedQueue<T> :: display()
{
    node *temp=rear->next;
    while(temp!=rear)
    {
        cout<<"  "<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<"  "<<temp->info;
}

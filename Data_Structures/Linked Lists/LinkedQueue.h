using namespace std;

template <class T>
class LinkedQueue
{
public:

    class node
    {
    public:
        T info;
        node *next;
    }*font,*rear;

    LinkedQueue()
    {
        font=rear=NULL;
    }
    void enqueue(T info);
    T dequeue();
    void display();
    bool isEmpty();

};
template <class T>
void LinkedQueue<T> :: enqueue(T info)
{
    node *temp= new node;
    temp->info=info;
    if(font==NULL)
    {
           font=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

template <class T>
T LinkedQueue<T> :: dequeue()
{
    node* temp=font;
    if(font->next==NULL)
    {
        font=rear=NULL;
    }
    else
    {
        font=font->next;
    }
    T info= temp->info;
    delete temp;
    return info;
}
template <class T>
bool LinkedQueue<T> :: isEmpty()
{
    if(font==NULL)
    {
        return true;
    }
    return false;
}
template <class T>

void LinkedQueue<T> :: display()
{
    node *temp=font;
    while(temp!=NULL)
    {
        cout<<"  "<<temp->info<<" ";
        temp=temp->next;
    }
}

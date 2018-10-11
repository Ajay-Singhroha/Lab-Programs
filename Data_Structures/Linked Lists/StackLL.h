using namespace std;

template <class T>
class LinkedStack
{
public:

    class Node
    {
    public:

        T info;
        Node *next;

    }*top;

    LinkedStack()
    {
        top=NULL;
    }
    void push(T info);
    T pop();
    T tos();
    bool isEmpty();
    void display();
};
template <class T>
void LinkedStack<T>:: push(T info)
{
    Node *temp=new Node;
    temp->info =info;
    temp->next = NULL ;
    if( top != NULL )
    {
        temp->next = top;
    }

    top=temp;
}
template <class T>
T LinkedStack<T> :: pop()
{
    Node *temp=top;
    top=temp->next;
    T info = temp->info;
    delete temp;
    return info;
}
template <class T>
T LinkedStack<T> :: tos()
{
    return top->info;
}
template <class T>
bool LinkedStack<T> :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}
template <class T>
void LinkedStack<T> :: display()
{
    Node * temp=top;
    while(temp!=NULL)
    {
        cout<<  "   "<<temp->info << "\n";

        temp=temp->next;
    }
}

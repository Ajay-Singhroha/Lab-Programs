# include <iostream>
using namespace std;

template <class T>
class LinkedList
{
public:
    class node
    {
    public:
        T info;
        node *next;
    }*header;

    LinkedList()
    {
       header=new node;
       header->next=NULL;
     
    }
    void insertInOrder(T info);
    bool insertAtPos(int pos, T info);
    bool insertAfter(T target, T info);
    bool insertBefore(T target, T info);
    void create(T info);
    void removeAll();
    void display();
    bool isEmpty();
    bool remov(T target);
    void revers();
};

/*template <class T>
void LinkedList<T> :: insertInOrder(T info)
{
    node *temp=new node;
    temp->info=info;
    temp->next=NULL;

    if(header==NULL)
    {
        header->next=temp;
        return ;
    }

    node *p=header->next;
    node *q=p;
    while(p!=NULL)
    {
        if(p->info>info)
            break;
        q=p;
        p=p->next;
    }

    if(p==header->next)
    {

        temp->next=header->next;
        header->next=temp;
    }
    else
    {
        temp->next=p;
        q->next=temp;
    }
}

template <class T>
bool LinkedList<T> :: insertAtPos(int pos, T info)
{
    int counter=0;
    node* temp=new node;
    temp->info=info;
    temp->next=NULL;

    node *p=header->next;
    node *q=p;

    if(p==NULL&&pos==1)
    {
        header->next=NULL;
        return true;
    }
    else if(p!=NULL&&pos==1)
    {
        temp->next=p;
        header->next=temp;
        return true;
    }

    else
    {
        while(p!=NULL)
        {
            counter++;
            if(counter==pos)
            {
                q->next=temp;
                temp->next=p;
                return true;
            }
            q=p;
            p=p->next;
        }
    }
    if(p==NULL&&counter==pos-1)
    {
        q->next=temp;
        return true;
    }

    return false;
}

template <class T>
bool LinkedList<T> :: insertAfter(T target, T info)
{
    node *temp= new node;
    temp->info=info;
    temp->next=NULL;

    node *p=header->next;
    node* q=p;



    while(p!= NULL)
    {
        if(p->info==target)
        {
            break;
        }
        p=p->next;
    }
    if(p==header->next)
    {
        temp->next=p->next;
        header->next=temp;
        return true;
    }
    if(p!=NULL)
    {
        temp->next=p->next;
        p->next=temp;
        return true;
    }

    return false;
}

template <class T>
bool LinkedList<T> :: insertBefore(T target, T info)
{
    node *temp= new node;
    temp->info=info;
    temp->next=NULL;

    node *p=header->next;
    node* q=p;



    while(p!= NULL)
    {
        if(p->info==target)
        {
            break;
        }
        q=p;
        p=p->next;
    }
    if(p==header->next)
    {
        temp->next=p;
        header->next=temp;
        return true;
    }
    if(p!=NULL)
    {
        temp->next=p;
        q->next=temp;
        return true;
    }

    return false;
}
*/
template <class T>
void LinkedList<T> :: create(T info)
{
    node *temp=new node;
    temp->info=info;
    temp->next=NULL;

    if(header->next==NULL)
     {   header->next=temp;
     	header->info++;
    	return ;
    }

    node* p=header->next;
    node * q=p;
    while(p!=NULL)
    {
    	q=p;
        p=p->next;
    }
    q->next=temp;
    header->info++;

}

template <class T>
void  LinkedList<T> :: display()
{
    node* temp=header->next;

    while(temp!=NULL)
    {
        cout<<"  "<<temp->info<<" ";
        temp=temp->next;
    }
}


template <class T>
bool LinkedList<T> :: remov(T target)
{
    node *temp=header->next;
    node *p=header->next;
    node *q=p;

    if(target==p->info)
    {
    	
    	header->next=p->next;
    	delete temp;
    	return true;
    }
    while(p!=NULL)
    {
        if(p->info==target)
        {
            temp=p;
            q->next=p->next;
            delete temp;
            return true;
        }
        q=p;
        p=p->next;
    }
    return false;
}
/*
template <class T>
void LinkedList<T> :: removeAll()
{
    node *temp=header->next;

    while(temp!=NULL)
    {
        header->next=temp->next;
        temp->next=NULL;
        free(temp);
        temp=header->next;
    }
}
*/
template <class T>
bool LinkedList<T> :: isEmpty()
{

    if(header->next==NULL)
      return true;
    
    return false;
}

template <class T>
void LinkedList<T> :: revers()
{
    node* temp;
    node *p=header->next;
    node* q=p;

    if(p==header->next)
    {
        p=p->next;
        q->next=NULL;
    }

    while(p!=NULL)
    {
        temp=p->next;
        p->next=q;

        q=p;
        p=temp;
    }
    header->next=q;

}




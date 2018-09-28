#include <iostream>
using namespace std;
class LinkedList
{
    public:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int d)
        {
            data=d;
        }
    }*first;

    void display()
    {
    }    //while();}
};
int main()
{
    //LinkedList ll;
    //ll->first;
    LinkedList::Node second(6);
    LinkedList::Node third(7);
    cout<<second.data;
    return 0;
}

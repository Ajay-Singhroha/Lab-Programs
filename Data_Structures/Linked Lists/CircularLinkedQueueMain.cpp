#include<iostream>
#include "CircularLinkedQueue.h"
using namespace std;

int main()
{
    int choice,info=0;
    CircularLinkedQueue<int> clq;
    do
    {
        cout<<"\n\n\n .,.,.,Circular Linked Queue,.,.,.";
        cout<<"\n\n 1. Enqueue \t\t\t\t\t 2.  Dequeue";
        cout<<"\n\n 3. Is  Empty \t\t\t\t\t 4. Display ";
        cout<<"\n\n\t\t\t\t 5. Exit \n";
        cout<<"\n\n\n  Enter your choice :: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            try
            {
                cout<<"\n\n Enter Element :: ";
                cin >> info;
                if(cin.fail())
                    throw info;
                clq.enqueue(info);
            }
            catch(int e)
            {
                cout<<"\n\n Wrong Input ! \n\n";
               return 0;
            }

            break;

        case 2:
            if(!clq.isEmpty())
            {
                cout<<"\n\n Element is :: "<<clq.dequeue();;

            }
            else
                cout<<"\n\n Queue Empty ! ";

            break;

        case 3:
            if(!clq.isEmpty())
            {
                cout<<"\n\n Queue is Not Empty ";
            }

            else
                cout<<"\n\n Queue Empty ! ";
            break;
        case 4:
            if(!clq.isEmpty())
            {
                cout<<"\n\n Element in Queue are  :: \n";
                clq.display();
            }
            else
                cout<<"\n\n Queue Empty ! ";

        case 5:
            break;
        default:
            break;
        }

    }
    while(choice<5);
}

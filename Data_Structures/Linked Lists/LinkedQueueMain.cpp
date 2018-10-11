#include<iostream>
#include "LinkedQueue.h"
using namespace std;

int main()
{
    int choice,info=0;
    LinkedQueue<int> lq;
    do
    {
        cout<<"\n\n\n .,.,.,Linked Queue,.,.,.";
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
                lq.enqueue(info);
            }
            catch(int e)
            {
                cout<<"\n\n Wrong Input ! \n\n";
               return 0;
            }

            break;

        case 2:
            if(!lq.isEmpty())
            {
                cout<<"\n\n Element is :: "<<lq.dequeue();;

            }
            else
                cout<<"\n\n Queue Empty ! ";

            break;

        case 3:
            if(!lq.isEmpty())
            {
                cout<<"\n\n Queue is Not Empty ";
            }

            else
                cout<<"\n\n Queue Empty ! ";
            break;
        case 4:
            if(!lq.isEmpty())
            {
                cout<<"\n\n Element in Queue are  :: \n";
                lq.display();
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

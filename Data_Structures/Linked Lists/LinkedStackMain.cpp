#include<iostream>
#include "StackLL.h"
using namespace std;

int main()
{
    int choice,info=0;
    LinkedStack<int> ls;
    do
    {
        cout<<"\n\n\n .,.,.,Linked Stack,.,.,.";
        cout<<"\n\n 1. Push \t\t\t\t\t 2.  Pop";
        cout<<"\n\n 3. Top of Stack \t\t\t\t 4. Display ";
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
                ls.push(info);
            }
            catch(int e)
            {
                cout<<"\n\n Wrong Input ! \n\n";
               return 0;
            }
            break;

        case 2:
            if(!ls.isEmpty())
            {
                cout<<"\n\n Element is :: "<<ls.pop();;

            }
            else
                cout<<"\n\n Stack Empty ! ";

            break;

        case 3:
            if(!ls.isEmpty())
            {
                cout<<"\n\n Top of Stack is :: "<<ls.tos();;

            }

            else
                cout<<"\n\n Stack Empty ! ";
            break;
        case 4:
            if(!ls.isEmpty())
            {
                cout<<"\n\n Element in stack are  :: \n";
                ls.display();
            }
            else
                cout<<"\n\n Stack Empty ! ";

        case 5:
            break;
        default:
            break;
        }

    }
    while(choice<5);
}

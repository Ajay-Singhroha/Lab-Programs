#include<iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    int choice,ichoice,rchoice,info=0,pos=0;
    LinkedList<int> l;
    do
    {
        cout<<"\n\n\n .,.,.,Linked Queue,.,.,.";
        cout<<"\n\n 1. Create \t\t\t\t\t 2.  Insert";
        cout<<"\n\n 3. Remove \t\t\t\t\t 4. Reverse ";
        cout<<"\n\n 5. Display \t\t\t\t\t 6. Exit ";
        cout<<"\n\n\n  Enter your choice :: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            try
            {
                if(!l.isEmpty())
                {
                	cout<<"\n\n List Exists! Select Insert Options .\n\n";
                	break;
                }
                cout<<"\n\n Enter Element. Press 0 to STOP !! \n\n";
                
                do
                {
   
   	          cin >> info;
   	          if(cin.fail())
   	                throw info;
   	      	  if(info!=0)	
     	         	  l.create(info);
                 }while(info!=0);
               
            }
            catch(int e)
            {
                cout<<"\n\n Wrong Input !! Try Again  \n\n";
                return 0;
            }

            break;

       /* case 2:
            do
            {
                cout<<"\n\n.......Insert Menu........\n";
                cout<<"\n\n 1. Insert In Order ";
                cout<<"\n\n 2. Insert At a Position ";
                cout<<"\n\n 3. Insert After a element ";
                cout<<"\n\n 4. Insert Before a element ";
                cout<<"\n\n 5. Back to previous menu <-  ";
                cout<<"\n\n\t Enter your choice :: ";
                cin>>ichoice;
                switch(ichoice)
                {
                case 1:
                    cout<<"\n\n Enter element :: ";
                    cin >> info;
                    l.insertInOrder(info);
                    break;
                case 2:
                    cout<<"\n\n Enter element :: ";
                    cin >> info;
                    cout<<"\n\n Enter Position :: ";
                    cin>>pos;
                    if(l.insertAtPos(pos,info))
                        cout<<"\n\n Insertion Success full .\n\n";
                    else
                        cout<<"\n\n Wrong Position \n\n";
                    break;
                case 3:
                    cout<<"\n\n Enter element :: ";
                    cin >> info;
                    cout<<"\n\n Enter Target :: ";
                    cin>>pos;
                    if(l.insertAfter(pos,info))
                        cout<<"\n\n Insertion Success full .\n\n";
                    else
                        cout<<"\n\n Target Not found !!\n\n";
                    break;
                case 4:
                    cout<<"\n\n Enter element :: ";
                    cin >> info;
                    cout<<"\n\n Enter Target :: ";
                    cin>>pos;
                    if(l.insertBefore(pos,info))
                        cout<<"\n\n Insertion Success full .\n\n";
                    else
                        cout<<"\n\n Target Not found !!\n\n";
                    break;
                case 5:
                    break;
                default:
                    break;

                }
            }
            while(ichoice<5);


       */ case 3:
            do
            {
                cout<<"\n\n ......Remove Menu ......\n\n";
                cout<<"\n\n 1. Remove one node ";
                cout<<"\n\n 2. Remove Complete List.";
                cout<<"\n\n 3. <<-- Back \n\n";
                cout<"\n\n\t Enter your choice :: ";
                cin >> rchoice;
                switch(rchoice)
                {
                case 1:
                    cout<<"\n\n Enter Target :: ";
                    cin >>pos;
                    if(l.remov(pos))
                        cout<<"\n\n Removal Success full \n\n";
                    else
                        cout<<"\n\n Target not found ! ";
                    break;
               // case 2:
                   // l.removeAll();
               //     break;
                case 3:
                    break;
                default:
                    break;
                }
            }
            while(rchoice<3);
            break;

        case 4:
            if(!l.isEmpty())
             {
                l.revers();
                l.display();
              }
           else
                cout<<"\n\n List Empty ! ";
            break;

        case 5:
            if(!l.isEmpty())
                l.display();
           else
                cout<<"\n\n List Empty ! ";
            break;
        default:
            break;
        }

    }
    while(choice<6);
    return 0;
}

#include <cstring>
#include <iostream>
using namespace std;
class block{
private:
    string id;
    int size;
public :
    block()
    {
        size=0;
        id="";
    }
    void input()
    {

        cout<<"\n\n Enter Size of Block :: ";
        cin>>size;
        while(size<=0)
        {
            cout<<"\n\n Error !!  Enter Again \n\n";
            cin >> size;
        }

    }
    int getSize()
    {
        return size;
    }
    string getId()
    {
        return id;
    }
     void display()
    {
        cout<<" "<<id<<"  :  "<<size;
    }

};

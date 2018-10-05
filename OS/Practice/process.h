#include <cstring>
#include <iostream>
using namespace std;
class process
{
private:
    string pid;
    int p_size;
public:
    process()
    {
        pid="";
        p_size=0;
    }
    void input()
    {

        cout<<"\n\n Enter Size :: ";
        cin >>p_size;
        while(p_size<=0)
        {
            cout<<"\n\n Invalid Process ! Enter Again \n\n ";
            cin>>p_size;

        }
    }
    int getPSize()
    {
        return p_size;
    }
    string getPId()
    {
        return pid;
    }
    void display()
    {
        cout<<" "<<pid<<"  :  "<<p_size;
    }
};

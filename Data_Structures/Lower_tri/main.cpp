#include <iostream>

using namespace std;
class LowerT
{
private:
    int arr[];
    int size;
public:
    LowerT(int siz)
    {
        size=siz*(siz+1)/2;
        for(int i=0;i<size;i++)
            arr[size*(size+1)/2]= 0;
    }
    void set(int i,int j,int value)
    {
        arr[i-1]=value;
    }
    int get(int i,int j)
    {
        return arr[i*(i+1)/2+j];
    }
    void display();

};
void LowerT::display()

{
    cout<<"\n Matrix is :: ";
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(j<=i)
                cout<<" "<<arr[i*(i+1)/2+j];
            else
                cout<<" "<<0;
        }
        cout<<endl;
    }
}
int main()
{
    LowerT d(4);int value=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cin>>value;
            d.set(i,j,value);
        }
    }

    cout<<endl<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(j<=i)
            cout<<d.get(i,j);
            else
            cout<<"  " <<0;
        }
    }
    d.display();
    return 0;
}

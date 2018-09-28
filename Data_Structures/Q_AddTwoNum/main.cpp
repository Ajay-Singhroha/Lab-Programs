#include <iostream>
#include "stack.cpp"
using namespace std;
void input( stack<int>& obj)
{
   int n=0;

    cout<<"\n\n Press -ve digit to terminate ! \n";
    while(cin>>n&&n>=0)
    {
        if(n/10>=1)
        {
            cout<<"\n\n Enter one digit at a time ";
            continue;
        }
        obj.push(n);
    }
}
int main()
{
    stack<int> obj1;
    stack<int> obj2;
    stack<int> result;

    cout<<"\n\n Enter First Number (Digit by Digit ):: ";
    input(obj1);

    cout<<"\n\n Enter Second (Digit by Digit ):: ";
    input(obj2);

    int temp=0;
    while(!obj1.checkStack_empty()&&!obj2.checkStack_empty())
    {

         temp=temp+obj1.pop()+obj2.pop();
        result.push(temp%10);
        temp/=10;
    }
    while(!obj1.checkStack_empty())
    {
        result.push(temp+obj1.pop());
    }
     while(!obj2.checkStack_empty())
    {
        result.push(temp+obj2.pop());
    }


    cout<<"\n\n Result is :: ";

    while(!result.checkStack_empty())
    cout<<result.pop();
    cout<<endl;
    return 0;
}

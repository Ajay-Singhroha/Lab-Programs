#include <iostream>
#include "stack.h"
using namespace std;

bool checkforOpening(char open,char close)
{
    if(close==')'&&open=='(')
        return true;
    else if(close=='}'&&open=='{')
        return true;
    else if(close==']'&&open=='[')
        return true;
    return false;

}
int main()
{
    bool flag=true;
    char choice;
    do
    {
        string s="";
        cout<<"\n\n Enter Expression ";
        cin >>s;
        stack<int> obj;

        int i=0;
        while(i<s.length())
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')
                obj.push(s[i]);
            else if(s[i]==']'||s[i]=='}'||s[i]==')')
            {
                if(obj.checkStack_empty()||!checkforOpening(obj.top(),s[i]))
                {
                    flag=false;
                    break;
                }
                else
                    obj.pop();
            }
            i++;
        }
        if(flag&&obj.checkStack_empty())
            cout<<"\n\n Expression Correct \n\n";
        else
            cout<<"\n\n Expression not correct \n\n";
        cout<<"\n\n Want to continue?? Press 'Y' :: ";
        cin>>choice;
    }
    while(choice=='y');

    return 0;
}

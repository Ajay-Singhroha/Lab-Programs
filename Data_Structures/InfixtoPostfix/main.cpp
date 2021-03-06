#include <iostream>
#include <string.h>
#include "stack.h"
#include "correctness.h"
using namespace std;
int priority(char c)
{
    switch(c)
    {
    case '$':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}
int compute(char pf[],string inf,stack<char>opr)
{
    int k=0;
    char s;
    for(int i=0; inf[i]!='\0'; i++)
    {
        s=inf[i];
        if(s>='0'&&s<='9')
        {
            pf[k++]=s;
        }
        else if(s=='(')
        {
            opr.push(s);
        }
        else if(s==')')
        {
            char x=opr.pop();
            while(x!='(')
            {
                pf[k++]=x;
                x=opr.pop();
            }
        }
        else
        {
            while(!opr.checkStack_empty()&&(priority(opr.top())>=priority(s)))
            {
                pf[k++]=opr.pop();

            }
            opr.push(s);
        }
    }
    while(!opr.checkStack_empty())
    {
        pf[k++]=opr.pop();
    }

    return k;
}
int main()
{
    stack<char> opr;
    string s;
    cout<<" \n\n Enter an Expression :: ";
    cin>>s;
    correctness c=new correctness(s);
    if(c.check())
    {
        char pf[50];
        int k=compute(pf,s,opr);
        cout<<"\n\n Postfix Expression is :: ";
        for(int i=0; i<k; i++)
        {
            cout<<" "<<pf[i];
        }
    }
    else cout<<"\n\n Enter Correct Expression !";
    return 0;
}

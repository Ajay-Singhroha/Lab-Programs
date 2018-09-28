#include "stack.h"
class correctness
{
    string s="";
    
public:
    correctness(string str)
    {
   	    s=str;
    }
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
    bool check()
    {
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
                    return false;
                }
                else
                    obj.pop();
            }
            i++;
        }

            return true;

    }
};

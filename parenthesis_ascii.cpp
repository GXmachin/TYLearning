#include <stack>
#include <string>

class Solution 
{
    public:
        bool isValid(string s) 
        {
            if(s.length() % 2 != 0) return false;
            stack<char> parenthesis;
            char prevTop;
            for(int i=0; i<s.length(); ++i)
            {
                if(parenthesis.size()) prevTop = parenthesis.top();
                parenthesis.push(s[i]);
                if(parenthesis.size() > 1 && (int(parenthesis.top()) == 41 || int(parenthesis.top()) == 93 || int(parenthesis.top()) == 125))
                {
                    if(!checkPar(prevTop, parenthesis.top())) return false;
                    if(checkPar(prevTop, parenthesis.top()))
                    {
                        parenthesis.pop();
                        parenthesis.pop();
                    }
                }
            }
            if((parenthesis.size() > 1))
               {
                   if(!checkPar(prevTop, parenthesis.top())) return false; 
               } 
            return true;
        }
    private:
    bool checkPar(char open, char close)
    {
        if(!(int(open) != 40 || int(open) != 91 || int(open) != 123))return false;
        if(!(int(close) != 40 || int(close) != 91 || int(close) != 123)) return false;
        if(int(open) == 40 && int(close) == 41) return true;
        if(int(open) == 91 && int(close) == 93) return true;
        if(int(open) == 123 && int(close) == 125) return true;
        return false;
    }
};

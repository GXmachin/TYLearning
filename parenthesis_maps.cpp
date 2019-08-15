#include <stack>
#include <string>
#include <unordered_map>

class Solution 
{
    public:
        bool isValid(string s) 
        {
            if(s.length() % 2 != 0) return false;
            unordered_map<char, char> brackets;
            brackets[']'] = '[';
            brackets['}'] = '{';
            brackets[')'] = '(';
            stack<char> parenthesis;
            char topChar;
            
            for(int i=0; i<s.length(); ++i)
            {
                if(brackets.find(s[i]) != brackets.end())
                {
                    topChar = parenthesis.empty() ? '*' : parenthesis.top();
                    if(topChar != brackets[s[i]]) return false;
                    parenthesis.pop();
                }
                else parenthesis.push(s[i]);
            }
            return parenthesis.empty();
        }
};

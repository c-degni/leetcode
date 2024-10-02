#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        char brackets[2][3] = {
            {'(', '{', '['}, 
            {')', '}', ']'}
        };

        if(s.length() == 1)
        {
            return false;
        }

        for(char bracket : s)
        {
            bool bracketFound = false;

            for(int i = 0; i < 3; i++)
            {
               if(bracket == brackets[0][i])
               {
                    bracketStack.push(bracket);
                    bracketFound = true;
                    break;
               }
            }

            if(!bracketFound)
            {
                if(bracketStack.empty())
                {
                    return false;
                }
                
                for(int j = 0; j < 3; j++)
                {
                    if(bracket == brackets[1][j] && bracketStack.top() == brackets[0][j] && !bracketStack.empty())
                    {
                        bracketStack.pop();
                        break;
                    }
                    else if(j == 2)
                    {
                        return false;
                    }
                }
            }
        }
        return bracketStack.empty();
    }
};

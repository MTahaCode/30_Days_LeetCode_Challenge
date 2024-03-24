class Solution {
public:
    bool isValid(string s) {
       stack<char> bracketStack;

        for (char curr : s)
        {
            if (curr == '[' || curr == '{' || curr == '(')
            {
                bracketStack.push(curr);
            }
            else if (bracketStack.empty()) return false;
            else
            {
                char bracket_from_stack = bracketStack.top();
                bracketStack.pop();

                if ((bracket_from_stack == '[' && curr != ']')
                    || (bracket_from_stack == '(' && curr != ')')
                    || (bracket_from_stack == '{' && curr != '}'))
                {
                    return false;
                }
            }
        }
        return bracketStack.empty(); 
    }
};
class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1) return false;
        stack<char> stack;
        for (char &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (!stack.size()) return false;
                if (c == ')' && stack.top() == '('
                || c == ']' && stack.top() == '[' 
                || c == '}' && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
};

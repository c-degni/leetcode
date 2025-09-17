class Solution {
public:
    string removeStars(string s) {
        std::stack<char> stack;
        int l = s.length();

        for (char &c : s) {
            if (c == '*') stack.pop();
            else stack.push(c);
        }

        int si = stack.size();
        string ns = "";
        for (int i = 0; i < si; i++) {
            ns += stack.top();
            stack.pop();
        }
        return reverseString(ns);
    }

    string reverseString(string &s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
        return s;
    }
};

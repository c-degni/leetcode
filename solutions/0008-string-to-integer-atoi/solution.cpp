class Solution {
public:
    int myAtoi(string s) {
        // Remove whitespace
        int w = 0;
        for (char &c : s) {
            if (c == ' ') w++;
            else break;
        }
        s = s.substr(w);

        // Check sign
        bool neg = false;
        if (s[0] == '-' || s[0] == '+') {
            if (s[0] == '-') neg = true;
            s = s.substr(1);
        }
        cout << s << "\n";

        // Get rid of leading zeroes
        while (s[0] == '0') {
            s = s.substr(1);
        }

        // Build num
        stack<int> stack;
        while (isdigit(s[0])) {
            stack.push(s[0] - '0');
            s = s.substr(1);
        }

        int num = 0;
        int exp = 0;
        if (stack.size() > 10) {
            if (neg) return INT_MIN;
            return INT_MAX;
        }
        while (!stack.empty()) {
            long res = num + stack.top() * pow(10, exp);
            if (res > INT_MAX) {
                if (neg) return INT_MIN;
                return INT_MAX;
            }
            num = res;
            stack.pop();
            exp++;
        }

        if (neg) return num * -1;
        return num; 
    }
};

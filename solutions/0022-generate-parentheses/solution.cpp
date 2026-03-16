class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        rec(0, 0, n, vector<char>(), out);
        return out;
    }

private:
    void rec(int open, int closed, int n, vector<char> tmp, vector<string>& out) {
        if (open == closed && open == n) {
            string s = "";
            for (char& c : tmp) s += c;
            out.push_back(s);
            return;
        }

        if (open < n) {
            tmp.push_back('(');
            rec(open + 1, closed, n, tmp, out);
            tmp.pop_back();
        }

        if (closed < open) {
            tmp.push_back(')');
            rec(open, closed + 1, n, tmp, out);
            tmp.pop_back();
        }
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string ns = "";
        for (char &c : s) {
            c = (char)tolower(c);
            if (isalnum(c)) ns += c;
        }
        int n = ns.length();
        for (int i = 0; i < n / 2; i++) {
            if (ns[i] != ns[n - i - 1]) return false;
        }
        return true;
    }
};

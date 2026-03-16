class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        int m = 1;
        string out = "";
        for (int i = 0; i < n; i++) {
            largestPalindromeFrom(i, false, s, out, m, n);
            largestPalindromeFrom(i, true, s, out, m, n);
        }
        return out;
    }

private:
    void largestPalindromeFrom(int i, bool even, string& s, string& out, int& m, int n) {
        int left = i;
        int right;
        if (even) right = i + 1;
        else right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (m <= right - left + 1) {
                m = right - left + 1;
                out = s.substr(left, m);
            }
            left--;
            right++;
        }
    }
};

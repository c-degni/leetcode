class Solution {
public:
    int maxVowels(string s, int k) {
        // Sliding window of size k
        // As window slides you can chop first char and add new end char of window
        int i = 0;
        int m = INT_MIN;
        int n = 0;
        while (i + k < s.length() + 1) {
            if (i == 0) {
                for (char &c : s.substr(i, k)) {
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') n++;
                }
            } else {
                if (s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u') n--;
                if (s[i + k - 1] == 'a' || s[i + k - 1] == 'e' || s[i + k - 1] == 'i' || s[i + k - 1] == 'o' || s[i + k - 1] == 'u') n++;
            }
            if (n > m) m = n;
            if (m == k) return k;
            i++;
        }
        return m;
    }
};

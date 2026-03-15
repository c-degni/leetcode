class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = tmp;
        }
        int c = 0;
        int i = 0;
        while (!c && i < n) {
            while (i < n && isalpha(s[i])) {
                c++;
                i++;
            }
            i++;
        }
        return c;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (slen > tlen || (tlen == slen && s != t)) return false;
        int i = 0;
        int j = 0;

        while (i < slen) {
            if (j == tlen) return false;
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return true;
    }
};

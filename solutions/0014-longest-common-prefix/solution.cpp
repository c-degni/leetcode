class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string prefix = strs[0];
        for (string &s : strs) {
            string np = "";
            int c = 0;
            while (c < s.length() && c < prefix.length()) {
                if (s[c] != prefix[c]) break;
                np += prefix[c];
                c++;
            }
            if (np == "") return np;
            prefix = np;
        }
        return prefix;
    }
};

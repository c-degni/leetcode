class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int n = s.size();
        string lastWord = "";
        while (i < n) {
            if (isalpha(s[i])) {
                lastWord = "";
                while (i < n && isalpha(s[i])) {
                    lastWord += s[i];
                    i++;
                }
            }
            i++;
        }
        return lastWord.length();
    }
};

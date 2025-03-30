class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int m = max(l1, l2);
        string mg = "";

        for (int i = 0; i < m; i++) {
            if (i < l1) {
                mg += word1[i];
            }

            if (i < l2) {
                mg += word2[i];
            }
        }
        return mg;
    }
};

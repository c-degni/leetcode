class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) return true;
        int c = strs[0].length();
        int res = 0;
        for (int j = 0; j < c; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

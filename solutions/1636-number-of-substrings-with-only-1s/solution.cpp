class Solution {
public:
    int numSub(string s) {
        int l = s.length();
        long ans = 0;
        int i = 0;
        while (i < l) {
            int n = 0;
            while (i < l && s[i] == '1') {
                n++;
                i++;
            }
            ans += (n + 1) * ((double)n / 2);
            i++;
        }
        return ans % (1000000007);
    }
};

class Solution {
public:
    int totalMoney(int n) {
        int t = 0;
        int i = 1;
        int f = 0;
        while (i < n + 1) { 
            int j = 1;
            while (j < 8 && j + i - 1 < n + 1) {
                t += j + f;
                j++;
            }
            f++;
            i += 7;
        }
        return t;
    }
};

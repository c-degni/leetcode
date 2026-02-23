class Solution {
public:
    int binaryGap(int n) {
        if (1 << (int)log2(n) == n) return 0;
        int m = 1;
        int f = 1;
        while (!(n & 1)) n = n >> 1;
        n = n >> 1;
        while (n != 0) {
            int tmp = n & 1;
            if (tmp == 0) {
                f++;
            } else {
                m = std::max(f, m);
                f = 1;
            }
            n = n >> 1;
        }
        return m;
    }
};

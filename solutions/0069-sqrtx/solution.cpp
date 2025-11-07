class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1;
        int right = x / 2;
        int m;
        while (left <= right) {
            m = left + (right - left) / 2;
            long long res = (long long)m * (long long)m;
            if (res == (long long)x) break;
            if (res < (long long)x && (long long)(m + 1) * (long long)(m + 1) > (long long)x) break;
            if (res < (long long)x) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        return m;
    }
};

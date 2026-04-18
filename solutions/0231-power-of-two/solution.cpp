class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return 0;
        int c = 0;
        while (n) {
            int r = n & 1;
            n >>= 1;
            if (r && n != 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    int smallestNumber(int n) {
        if (!(n & (n + 1))) return n;
        int k = 0;
        while (n != 0) {
            k++;
            n = n >> 1;
        }

        return std::pow(2, k) - 1;
    }
};

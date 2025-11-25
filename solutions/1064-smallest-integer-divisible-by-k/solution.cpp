class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int d = 1;
        int r = 1;
        set<int> seen;
        while (r % k) {
            if (seen.count(r)) return -1;
            seen.insert(r);
            r = (r % k) * 10 + 1;
            d++;
        }
        return d;
    }
};

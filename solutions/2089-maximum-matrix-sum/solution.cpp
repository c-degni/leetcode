class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s = 0;
        bool odd = false;
        int m = INT_MAX;
        for (auto &r : matrix) {
            for (int &c : r) {
                if (c < 0) odd = !odd;
                m = min(abs(m), abs(c));
                s += abs(c);
            }
        }
        if (odd) s -= 2 * m;
        return s;
    }
};

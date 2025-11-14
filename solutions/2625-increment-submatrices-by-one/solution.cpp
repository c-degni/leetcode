class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Run through queries once and keep track of incremented vals
        vector<vector<int>> v(n, vector<int>(n, 0));
        map<pair<int, int>, int> m; // m[indices] = val
        for (auto &q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                for (int j = q[1]; j <= q[3]; j++) {
                    v[i][j]++;
                }
            }
        }
        return v;
    }
};

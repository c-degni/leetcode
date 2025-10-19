class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zr;
        set<int> zc;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zr.insert(i);
                    zc.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (zr.contains(i)) matrix[i] = vector<int>(matrix[0].size(), 0);
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (zc.contains(i)) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            } 
        }
    }
};

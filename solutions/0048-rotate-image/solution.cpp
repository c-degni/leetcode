class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
private:
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[0].size(); j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};

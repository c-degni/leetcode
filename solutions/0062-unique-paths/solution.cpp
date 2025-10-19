class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) {
                    paths[i][j] = 1;
                } else if (j == n - 1) {
                    paths[i][j] = 1;
                } else {
                    paths[i][j] = paths[i+1][j] + paths[i][j+1];
                }

            }
        }
        return paths[0][0];
    }
};

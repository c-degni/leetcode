class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int row = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            if (target > matrix[mid][n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (row == -1) return false;

        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == matrix[row][mid]) return true;
            if (target > matrix[row][mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

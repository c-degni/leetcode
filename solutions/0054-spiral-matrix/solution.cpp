class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix[0].size();
        vector<int> out;
        int i = 0;
        int j = 0;

        while (top < bottom && left < right) {
            while (j < right) {
                out.push_back(matrix[i][j]);
                j++;
            }
            j--;
            i++;
            top++;

            while (i < bottom) {
                out.push_back(matrix[i][j]);
                i++;
            }
            i--;
            j--;
            right--;

            if (top >= bottom || left >= right) break;

            while (j >= left) {
                out.push_back(matrix[i][j]);
                j--;
            }
            j++;
            i--;
            bottom--;

            while (i >= top) {
                out.push_back(matrix[i][j]);
                i--;
            }
            i++;
            j++;
            left++;
        }

        return out;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> original = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(matrix[row][col] == 0 && original[row][col] == 0)
                {
                    for(int i = 0; i < rows; i++)
                    {
                        matrix[i][col] = 0;
                    }

                    for(int j = 0; j < cols; j++)
                    {
                        matrix[row][j] = 0;
                    }
                }
            }
        }
    }
};

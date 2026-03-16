class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int c) {
        if (c == word.size()) return true;
        if (i < 0 || i >= board.size()) return false;
        if (j < 0 || j >= board[0].size()) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[c]) return false;

        visited[i][j] = true;

        if (dfs(board, word, visited, i - 1, j, c + 1) ||
            dfs(board, word, visited, i + 1, j, c + 1) ||
            dfs(board, word, visited, i, j - 1, c + 1) ||
            dfs(board, word, visited, i, j + 1, c + 1))
        {
            return true;
        }

        visited[i][j] = false;
        return false;
    }
};

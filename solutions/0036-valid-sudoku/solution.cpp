class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> possible = {
            {'1', 1},
            {'2', 1},
            {'3', 1},
            {'4', 1},
            {'5', 1},
            {'6', 1},
            {'7', 1},
            {'8', 1},
            {'9', 1}
        };

        for (auto &r : board) {
            unordered_map<char, int> tmp = possible;
            for (char &c : r) {
                if (c == '.') continue;
                if (tmp[c] == 0) return false;
                tmp[c]--;
            }
        }

        for (int j = 0; j < 9; j++) {
            unordered_map<char, int> tmp = possible;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (tmp[board[i][j]] == 0) return false;
                tmp[board[i][j]]--;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_map<char, int> tmp = possible;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        if (tmp[board[k][l]] == 0) return false;
                        tmp[board[k][l]]--;
                    }
                }
            }
        }

        return true;
    }
};

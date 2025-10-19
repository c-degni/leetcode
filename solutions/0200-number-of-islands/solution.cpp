class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int isl = 0;
        set<pair<int, int>> d;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !d.contains(make_pair(i, j))) {
                    isl++;
                    dfs(grid, d, make_pair(i , j));
                }
            }
        }
        return isl;
    }
private:
    void dfs(vector<vector<char>> &grid, set<pair<int, int>> &discovered, pair<int, int> cell) {
        if (grid[cell.first][cell.second] == '0' || discovered.contains(cell)) { // Water or discovered
            return;
        }

        discovered.insert(cell);

        if (cell.first - 1 >= 0) {
            dfs(grid, discovered, make_pair(cell.first - 1, cell.second));
        }
        if (cell.first + 1 < grid.size()) {
            dfs(grid, discovered, make_pair(cell.first + 1, cell.second));
        }
        if (cell.second - 1 >= 0) {
            dfs(grid, discovered, make_pair(cell.first, cell.second - 1));
        }
        if (cell.second + 1 < grid[0].size()) {
            dfs(grid, discovered, make_pair(cell.first, cell.second + 1));
        }
    }
};

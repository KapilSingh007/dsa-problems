class Solution {
    public:
        vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
        void dfs(vector<vector<char>>& grid, int& m, int& n, int i, int j) {
    
            grid[i][j] = '2';
    
            for (int k = 0; k < 4; k++) {
                int r = i + row[k], c = j + col[k];
    
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    dfs(grid, m, n, r, c);
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
    
            int m = grid.size(), n = grid[0].size(), res = 0;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1') {
                        dfs(grid, m, n, i, j);
                        res++;
                    }
                }
            }
    
            return res;
        }
    };
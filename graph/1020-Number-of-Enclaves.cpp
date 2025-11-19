class Solution {
    public:
        vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
    
        void markVisited(vector<vector<int>>& grid, vector<vector<int>>& vis,
                         int& m, int& n, int i, int j) {
            vis[i][j] = 1;
    
            for (int k = 0; k < 4; k++) {
                int r = i + row[k], c = j + col[k];
                if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] &&
                    grid[r][c] == 1) {
                    markVisited(grid, vis, m, n, r, c);
                }
            }
        }
        int numEnclaves(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size(), res = 0;
            vector<vector<int>> vis(m, vector<int>(n, 0));
    
            for (int i = 0; i < m; i++) {
                if (!vis[i][0] && grid[i][0] == 1) {
                    markVisited(grid, vis, m, n, i, 0);
                }
    
                if (!vis[i][n - 1] && grid[i][n - 1] == 1) {
                    markVisited(grid, vis, m, n, i, n - 1);
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (!vis[0][i] && grid[0][i] == 1) {
                    markVisited(grid, vis, m, n, 0, i);
                }
    
                if (!vis[m - 1][i] && grid[m - 1][i] == 1) {
                    markVisited(grid, vis, m, n, m - 1, i);
                }
            }
    
            for (int i = 1; i <= m - 2; i++) {
                for (int j = 1; j <= n - 2; j++) {
                    if (!vis[i][j] && grid[i][j] == 1) {
                        res++;
                    }
                }
            }
            return res;
        }
    };
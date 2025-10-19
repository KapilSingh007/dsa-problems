class Solution {
    public:
        int helper(vector<vector<int>>& grid, int& n, int& m, int i, int j1, int j2,
                   vector<vector<vector<int>>>& dp) {
    
            if (i == n - 1) {
                if (j1 == j2) {
                    return grid[i][j1];
                } else {
                    return grid[i][j1] + grid[i][j2];
                }
            }
    
            if (dp[i][j1][j2] != -1)
                return dp[i][j1][j2];
    
            int res = 0;
            for (int d1 = -1; d1 <= 1; d1++) {
                if (j1 + d1 < 0 || j1 + d1 >= m) {
                    continue;
                }
                for (int d2 = -1; d2 <= 1; d2++) {
                    if (j2 + d2 < 0 || j2 + d2 >= m) {
                        continue;
                    }
                    if (j1 == j2) {
                        res = max(res, grid[i][j2] + helper(grid, n, m, i + 1,
                                                            j1 + d1, j2 + d2, dp));
                    } else {
                        res = max(res, grid[i][j1] + grid[i][j2] +
                                           helper(grid, n, m, i + 1, j1 + d1,
                                                  j2 + d2, dp));
                    }
                }
            }
    
            return dp[i][j1][j2] = res;
        }
        int cherryPickup(vector<vector<int>>& grid) {
    
            int n = grid.size(), m = grid[0].size();
            vector<vector<vector<int>>> dp(
                n, vector<vector<int>>(m, vector<int>(m, -1)));
            return helper(grid, n, m, 0, 0, m - 1, dp);
        }
    };
class Solution {
    public:
        int helper(vector<vector<int>>& grid, int& m, int& n, int i, int j,
                   vector<vector<int>>& dp) {
    
            if (i == m - 1 && j == n - 1)
                return grid[i][j];
            
            if(dp[i][j] != -1) return dp[i][j];
    
            int down = i + 1 != m ? grid[i][j] + helper(grid, m, n, i + 1, j, dp)
                                  : INT_MAX;
            int right = j + 1 != n ? grid[i][j] + helper(grid, m, n, i, j + 1, dp)
                                   : INT_MAX;
    
            return dp[i][j] = min(down, right);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
    
            return helper(grid, m, n, 0, 0, dp);
        }
    };
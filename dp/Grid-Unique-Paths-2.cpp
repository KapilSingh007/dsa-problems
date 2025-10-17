class Solution {
    public:
        int helper(vector<vector<int>>& obs, int& m, int& n, int i, int j,
                   vector<vector<int>>& dp) {
    
            if (i == m || j == n || obs[i][j] == 1)
                return 0;
            if (i == m - 1 && j == n - 1)
                return 1;
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            int down = helper(obs, m, n, i + 1, j, dp);
            int right = helper(obs, m, n, i, j + 1, dp);
    
            return dp[i][j] = down + right;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obs) {
            int m = obs.size(), n = obs[0].size();
            if (obs[m - 1][n - 1] == 1)
                return 0;
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
    
            return helper(obs, m, n, 0, 0, dp);
        }
    };
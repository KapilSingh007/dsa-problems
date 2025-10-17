class Solution {
    public:
        int helper(vector<vector<int>>& tri, int m, int i, int j,
                   vector<vector<int>>& dp) {
    
            if (i == m - 1)
                return tri[i][j];
    
            if (dp[i][j] != INT_MIN)
                return dp[i][j];
    
            int same = tri[i][j] + helper(tri, m, i + 1, j, dp);
            int oneStep = tri[i][j] + helper(tri, m, i + 1, j + 1, dp);
    
            return dp[i][j] = min(same, oneStep);
        }
        int minimumTotal(vector<vector<int>>& tri) {
    
            int m = tri.size();
            vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
    
            return helper(tri, m, 0, 0, dp);
        }
    };
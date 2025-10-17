class Solution {
    public:
        int helper(vector<vector<int>>& mat, int n, int i, int j,
                   vector<vector<int>>& dp) {
    
            if (i == n - 1)
                return mat[i][j];
    
            if (dp[i][j] != INT_MIN)
                return dp[i][j];
            int down = mat[i][j] + helper(mat, n, i + 1, j, dp);
            int right =
                j + 1 != n ? mat[i][j] + helper(mat, n, i + 1, j + 1, dp) : INT_MAX;
            int left =
                j - 1 >= 0 ? mat[i][j] + helper(mat, n, i + 1, j - 1, dp) : INT_MAX;
    
            return dp[i][j] = min({left, right, down});
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int res = INT_MAX;
            vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
            for (int i = 0; i < n; i++) {
                res = min(res, helper(matrix, n, 0, i,dp));
            }
    
            return res;
        }
    };
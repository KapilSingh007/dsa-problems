class Solution {
    public:
        int approach1Recurssion(vector<int>& p, int n, int& fee, int i, int isBuyed,
                                vector<vector<int>>& dp) {
    
            if (i >= n)
                return 0;
    
            if (dp[i][isBuyed] != -1) {
                return dp[i][isBuyed];
            }
            if (isBuyed) {
                return dp[i][isBuyed] =
                           max(p[i] - fee +
                                   approach1Recurssion(p, n, fee, i + 1, 0, dp),
                               approach1Recurssion(p, n, fee, i + 1, 1, dp));
            } else {
                return dp[i][isBuyed] =
                           max(-p[i] + approach1Recurssion(p, n, fee, i + 1, 1, dp),
                               approach1Recurssion(p, n, fee, i + 1, 0, dp));
            }
        }
        int maxProfit(vector<int>& p, int fee) {
            int n = p.size();
            vector<vector<int>> dp(n, vector<int>(2, -1));
            return approach1Recurssion(p, n, fee, 0, 0, dp);
        }
    };
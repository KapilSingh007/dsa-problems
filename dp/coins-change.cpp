class Solution {
    public:
        int twoDDp(vector<int>& coins, int amount, int n) {
            vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    
            for (int i = 1; i <= n; i++) {
                dp[i][0] = 0;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= amount; j++) {
                    if (coins[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        if (dp[i - 1][j] == -1) {
                            if (dp[i][j - coins[i - 1]] != -1) {
                                dp[i][j] = 1 + dp[i][j - coins[i - 1]];
                            }
                        } else {
                            if (dp[i][j - coins[i - 1]] == -1) {
                                dp[i][j] = dp[i - 1][j];
                            } else {
                                dp[i][j] =
                                    min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                            }
                        }
                    }
                }
            }
            return dp[n][amount];
        }
    
        int oneDDP(vector<int>& coins, int amount, int n) {
            vector<int> dp(amount + 1, -1);
            dp[0] = 0;
    
            for (int i = 1; i <= n; i++) {
                for (int j = coins[i - 1]; j <= amount; j++) {
                    if (dp[j] == -1) {
                        if (dp[j - coins[i - 1]] != -1) {
                            dp[j] = 1 + dp[j - coins[i - 1]];
                        }
                    } else {
                        if (dp[j - coins[i - 1]] != -1) {
                            dp[j] = min(dp[j], 1 + dp[j - coins[i - 1]]);
                        }
                    }
                }
            }
    
            return dp[amount];
        }
        int coinChange(vector<int>& coins, int amount) {
            if (amount == 0)
                return 0;
    
            int n = coins.size();
    
            // return twoDDp(coins,amount,n);
            return oneDDP(coins,amount,n);
    
            
        }
    };
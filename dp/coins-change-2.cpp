class Solution {
    public:
        int recursive(int amount, vector<int>& coins, int n, int idx,
                   vector<vector<int>>& dp) {
            if (amount == 0)
                return dp[idx][amount] = 1;
    
            if (idx == n) {
                return 0;
            }
    
            if (dp[idx][amount] != -1)
                return dp[idx][amount];
    
            int take = 0, notTake = 0;
    
            notTake = recursive(amount, coins, n, idx + 1, dp);
            if (coins[idx] <= amount) {
                take = recursive(amount - coins[idx], coins, n, idx, dp);
            }
    
            return dp[idx][amount] = take + notTake;
        }
        int change(int amount, vector<int>& coins) {
            if (amount == 0)
                return 1;
            int n = coins.size();
            vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    

            return recursive(amount, coins, n, 0, dp);
        }
    };
class Solution {
    public:
        int approach1Recurssion(vector<int>& p, int& n, int i, int txn, int isBuyed,
                                vector<vector<vector<int>>>& dp) {
    
            if (txn >= 2 || i == n) {
                return 0;
            }
    
            if (dp[i][isBuyed][txn] != -1) {
                return dp[i][isBuyed][txn];
            }
            if (isBuyed) {
                return dp[i][isBuyed][txn] = max(
                           p[i] + approach1Recurssion(p, n, i + 1, txn + 1, 0, dp),
                           approach1Recurssion(p, n, i + 1, txn, 1, dp));
            } else {
                return dp[i][isBuyed][txn] =
                           max(-p[i] + approach1Recurssion(p, n, i + 1, txn, 1, dp),
                               approach1Recurssion(p, n, i + 1, txn, 0, dp));
            }
        }
    
        int approach2Tabulation(vector<int>& p, int n) {
            vector<vector<vector<int>>> dp(
                n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    
            for (int i = n-1; i >=0 ; i--) {
                for (int isBuyed = 0; isBuyed < 2; isBuyed++) {
                    for (int txn = 1; txn <= 2; txn++) {
                        if (isBuyed) {
                            dp[i][isBuyed][txn] =
                                max(p[i] + dp[i + 1][!isBuyed][txn - 1],
                                    dp[i + 1][isBuyed][txn]);
                        } else {
    
                            dp[i][isBuyed][txn] =
                                max(-p[i] + dp[i + 1][!isBuyed][txn],
                                    dp[i + 1][isBuyed][txn]);
                        }
                    }
                }
            }
    
            return dp[0][0][2];
        }
        int maxProfit(vector<int>& p) {
            int n = p.size();
            // vector<vector<vector<int>>> dp(
            //     n, vector<vector<int>>(2, vector<int>(3, -1)));
            // return approach1Recurssion(p, n, 0, 0, 0, dp);
    
            return approach2Tabulation(p, n);
        }
    };
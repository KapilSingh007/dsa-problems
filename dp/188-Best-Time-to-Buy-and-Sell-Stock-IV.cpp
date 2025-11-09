class Solution {
    public:
        int approach1Recurssion(vector<int>& p, int& n, int& k, int i, int txn,
                                int isBuyed, vector<vector<vector<int>>>& dp) {
    
            if (txn >= k || i == n) {
                return 0;
            }
    
            if (dp[i][isBuyed][txn] != -1) {
                return dp[i][isBuyed][txn];
            }
            if (isBuyed) {
                return dp[i][isBuyed][txn] =
                           max(p[i] + approach1Recurssion(p, n, k, i + 1, txn + 1,
                                                          0, dp),
                               approach1Recurssion(p, n, k, i + 1, txn, 1, dp));
            } else {
                return dp[i][isBuyed][txn] = max(
                           -p[i] + approach1Recurssion(p, n, k, i + 1, txn, 1, dp),
                           approach1Recurssion(p, n, k, i + 1, txn, 0, dp));
            }
        }
        int maxProfit(int k, vector<int>& p) {
            int n = p.size();
            vector<vector<vector<int>>> dp(
                n, vector<vector<int>>(2, vector<int>(k, -1)));
            return approach1Recurssion(p, n, k, 0, 0, 0, dp);
        }
    };
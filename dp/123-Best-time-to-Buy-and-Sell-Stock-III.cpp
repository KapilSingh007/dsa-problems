class Solution {
    public:
        int approach1Recurssion(vector<int>& p, int& n, int i, int txn, int isBuyed,
                                int lastEle, vector<vector<vector<int>>>& dp) {
    
            if (txn >= 2 || i == n) {
                return 0;
            }
    
            if (dp[i][isBuyed][txn] != -1) {
                return dp[i][isBuyed][txn];
            }
            if (isBuyed) {
                return dp[i][isBuyed][txn] = max(
                           p[i] +
                               approach1Recurssion(p, n, i + 1, txn + 1, 0, -1, dp),
                           approach1Recurssion(p, n, i + 1, txn, 1, lastEle, dp));
            } else {
                return dp[i][isBuyed][txn] = max(
                           -p[i] +
                               approach1Recurssion(p, n, i + 1, txn, 1, p[i], dp),
                           approach1Recurssion(p, n, i + 1, txn, 0, lastEle, dp));
            }
        }
    
        
        int maxProfit(vector<int>& p) {
            int n = p.size();
            vector<vector<vector<int>>> dp(
                n, vector<vector<int>>(2, vector<int>(3, -1)));
            return approach1Recurssion(p, n, 0, 0, 0, -1, dp);
        }
    };
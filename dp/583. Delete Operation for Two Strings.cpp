class Solution {
    public:
        int helper(string w1, string w2, int& n1, int& n2, int i, int j,
                   vector<vector<int>>& dp) {
    
            if (i == n1) {
                return n2 - j;
            }
    
            if (j == n2) {
                return n1 - i;
            }
    
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
    
            if (w1[i] == w2[j]) {
                return dp[i][j] = helper(w1, w2, n1, n2, i + 1, j + 1, dp);
            }
    
            return dp[i][j] = 1 + min(helper(w1, w2, n1, n2, i, j + 1, dp),
                                      helper(w1, w2, n1, n2, i + 1, j, dp));
        }
        int minDistance(string w1, string w2) {
    
            int n1 = w1.size(), n2 = w2.size();
    
            vector<vector<int>> dp(n1, vector<int>(n2, -1));
            return helper(w1, w2, n1, n2, 0, 0, dp);
        }
    };
class Solution {
    public:
        int tabulation(string& s1, string& s2, int& n1, int& n2) {
            int res = 0;
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    
            for (int i = 1; i <= n1; i++) {
                for (int j = 1; j <= n2; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        res = max(res, dp[i][j]);
                    }
                }
            }
    
            return res;
        }
        // {adac, adadac}
        int recurrsion(string& s1, string& s2, int& n1, int& n2, int i, int j,
                       int& res, vector<vector<int>>& dp) {
            if (i == n1 || j == n2) {
                return 0;
            }
    
            if (dp[i][j] != -1) {
    
                return dp[i][j];
            }
    
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + recurrsion(s1, s2, n1, n2, i + 1, j + 1, res, dp);
    
            } else {
                dp[i][j] = 0;
            }
            int val = max(recurrsion(s1, s2, n1, n2, i + 1, j, res, dp),
                          recurrsion(s1, s2, n1, n2, i, j + 1, res, dp));
            res = max(res, dp[i][j]);
            res = max(res, val);
            return dp[i][j];
        }
        int longestCommonSubstr(string& s1, string& s2) {
            // your code here
    
            int n1 = s1.size(), n2 = s2.size(), res = 0;
    
            // return tabulation(s1,s2,n1,n2);
    
            vector<vector<int>> dp(n1, vector<int>(n2, -1));
            recurrsion(s1, s2, n1, n2, 0, 0, res, dp);
            return res;
        }
    };

//   adac
//   adadac

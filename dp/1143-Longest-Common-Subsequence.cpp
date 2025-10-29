class Solution {
    public:
        int recurrsion1(string& text1, string& text2, int& n1, int& n2, int i,
                        int j, vector<vector<int>>& dp) {
    
            if (i == n1 || j == n2) {
                return 0;
            }
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if (text1[i] == text2[j]) {
                return dp[i][j] =
                           1 + recurrsion1(text1, text2, n1, n2, i + 1, j + 1, dp);
            } else {
                return dp[i][j] =
                           max(recurrsion1(text1, text2, n1, n2, i + 1, j, dp),
                               recurrsion1(text1, text2, n1, n2, i, j + 1, dp));
            }
        }
    
        int recurrsion2(string& text1, string& text2, int& n1, int& n2, int i,
                        int j, vector<vector<int>>& dp) {
    
            if (i == -1 || j == -1) {
                return 0;
            }
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if (text1[i] == text2[j]) {
                return dp[i][j] =
                           1 + recurrsion2(text1, text2, n1, n2, i - 1, j - 1, dp);
            } else {
                return dp[i][j] =
                           max(recurrsion2(text1, text2, n1, n2, i - 1, j, dp),
                               recurrsion2(text1, text2, n1, n2, i, j - 1, dp));
            }
        }

        int tabulation(string& text1, string& text2, int& n1, int& n2) {
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    
            for (int i = 1; i <= n1; i++) {
                for (int j = 1; j <= n2; j++) {
                    if (text1[i-1] == text2[j-1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[n1][n2];
        }

        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size(), n2 = text2.size();

            // BY RECURSION
            // vector<vector<int>> dp(n1, vector<int>(n2, -1));
            // return recurrsion1(text1, text2, n1, n2, 0, 0, dp); O(2^n1 * 2^n2) if recurrsion calls are made without using dp 
            // return recurrsion2(text1, text2, n1, n2, n1 - 1, n2 - 1, dp); O(2^n1 * 2^n2) if recurrsion calls are made using dp

            // BY TABULATION
            return tabulation(text1, text2, n1, n2);
        }
    };
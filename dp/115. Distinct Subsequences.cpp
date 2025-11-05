class Solution {
    public:
        int approach1Recurrsion(string& s, string& t, int& n, int& m, int i, int j,
                                vector<vector<int>>& dp) {
    
            if (j == m) {
                return 1;
            }
    
            if (i == n) {
                return 0;
            }
    
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if (s[i] == t[j]) {
                return dp[i][j] =
                           approach1Recurrsion(s, t, n, m, i + 1, j + 1, dp) +
                           approach1Recurrsion(s, t, n, m, i + 1, j, dp);
            } else {
                return dp[i][j] = approach1Recurrsion(s, t, n, m, i + 1, j, dp);
            }
        }

        int numDistinct(string s, string t) {
            int n = s.size(), m = t.size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            return approach1Recurrsion(s, t, n, m, 0, 0, dp);
    
          
        }
    };
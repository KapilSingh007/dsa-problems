// User function template for C++

class Solution {
    public:
      // Function to find length of shortest common supersequence of two strings.
      int helper(string& text1, string& text2, int& n1, int& n2, int i, int j,
                 vector<vector<int>>& dp) {
  
          if (i == n1 || j == n2)
              return 0;
  
          if (dp[i][j] != -1)
              return dp[i][j];
  
          if (text1[i] == text2[j]) {
              return dp[i][j] =
                         1 + helper(text1, text2, n1, n2, i + 1, j + 1, dp);
          }
  
          return dp[i][j] = max(helper(text1, text2, n1, n2, i + 1, j, dp),
                                helper(text1, text2, n1, n2, i, j + 1, dp));
      }
      int shortestCommonSupersequence(string &text1, string &text2) {
          // code here
          int n1 = text1.size(), n2 = text2.size();
          vector<vector<int>> dp(n1, vector<int>(n2, -1));
          int lcs = helper(text1, text2, n1, n2, 0, 0, dp);
  
          return n1 + n2 - lcs;
      }
  };
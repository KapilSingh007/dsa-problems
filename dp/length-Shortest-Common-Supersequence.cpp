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
      int approach1Recurrsion1(string &text1, string &text2,int& n1, int& n2,int i, int j, vector<vector<int>>& dp){
        if(i==n1){
            return n2 - j;
        }
        
         if(j==n2){
            return n1 - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + approach1Recurrsion(text1, text2, n1, n2, i+1, j+1, dp);
        }else{
            return dp[i][j] = 1 + min(approach1Recurrsion(text1, text2, n1, n2, i+1, j, dp),approach1Recurrsion(text1, text2, n1, n2, i, j+1, dp));
        }
        
    }

    int approach1Recurrsion2(string &text1, string &text2,int& n1, int& n2,int i, int j,vector<vector<int>>& dp){
        if(i==0 || j==0){
            return i + j;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(text1[i-1] == text2[j-1]){
            return dp[i][j] = 1 + approach1Recurrsion2(text1, text2, n1, n2, i-1, j-1, dp);
        }else{
            return dp[i][j] = 1 + min(approach1Recurrsion2(text1, text2, n1, n2, i-1, j, dp),approach1Recurrsion2(text1, text2, n1, n2, i, j-1, dp));
        }
        
    }
    int approach2BottomUp(string &text1, string &text2,int& n1, int& n2){
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0){
                    dp[i][j] = j+i;
                }else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]); 
                }
            }
        }
        
        return dp[n1][n2];
        
    }

      int shortestCommonSupersequence(string &text1, string &text2) {
          // code here
          int n1 = text1.size(), n2 = text2.size();
        /*
          Below Code is by logic first find the longest common subsequence and then subtract it from the total length of the two strings
          vector<vector<int>> dp(n1, vector<int>(n2, -1));
          int lcs = helper(text1, text2, n1, n2, 0, 0, dp);
  
          return n1 + n2 - lcs;
        */

        /*
        BY RECURRSION approach1
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return approach1Recurrsion1(text1, text2, n1, n2, 0, 0, dp);

        return approach1Recurrsion2(text1, text2, n1, n2, n1, n2, dp);
        */

        /*
        BY TABULATION approach2
        return approach2BottomUp(text1, text2, n1, n2);
        */
      
      }
  };
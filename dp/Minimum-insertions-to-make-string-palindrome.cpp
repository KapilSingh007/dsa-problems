class Solution {
    public:
    
        int helper(string& s, int& n,int i,int j,vector<vector<int>>& dp){
    
            if(i >= j){
                return 0;
            }
    
            if(dp[i][j] != -1) return dp[i][j];
    
    
            if(s[i] == s[j]){
                return dp[i][j] = helper(s,n,i+1,j-1,dp);
            }
            return dp[i][j] = 1 + min(helper(s,n,i+1,j,dp), helper(s,n,i,j-1,dp));
        }
        int minInsertions(string s) {
            int n = s.size();
    
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return helper(s,n,0,n-1,dp);
        }
    };
class Solution {
    public:
      
      int helper(int n,vector<int> &price,vector<int>& dp){
          if(n==1){
               return price[n-1];
          }
          
          if(dp[n] !=-1) return dp[n];
          
          int res = price[n-1];
          for(int i=1;i<n;i++){
              res = max(res,helper(i,price,dp) + helper(n-i,price,dp));
          }
          
          return dp[n] = res;
      }
      int cutRod(vector<int> &price) {
          // code here
          int n= price.size();
          vector<int> dp(n+1,-1);
          return helper(n,price,dp);
      }
  };
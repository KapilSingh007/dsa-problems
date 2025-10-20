class Solution {
    public:
      int helper(vector<int>& arr,int n,int idx, int target,vector<vector<int>>& dp){
          
          if(target<0){return 0;}
          
          if(idx==n){
              if(target==0){return 1;}
              return 0;
          }
          
          if(dp[idx][target]!=-1) return dp[idx][target];
          
          return dp[idx][target] = helper(arr,n,idx+1,target-arr[idx],dp) + helper(arr,n,idx+1,target,dp);
      }
      int perfectSum(vector<int>& arr, int target) {
          // code here
          int n= arr.size();

          // BY RECURSION
          vector<vector<int>> dp(n,vector<int>(target+1,-1));
          return helper(arr,n,0,target,dp);


          // BY TABULATION
          vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        dp[0][0] = 1;
    
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(arr[i-1] <= j){
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[n][target];

      }
  };
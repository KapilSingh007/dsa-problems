class Solution {
    public:
      bool helper(vector<int>& arr,int n,int idx, int sum,vector<vector<int>>& dp){
          
          if(sum==0) return true;
          if(sum < 0) return false;
          if(idx == n) return false;
          
          if(dp[idx][sum] != -1) return dp[idx][sum];
          return dp[idx][sum] = helper(arr,n,idx+1,sum,dp)  ||  helper(arr,n,idx+1,sum - arr[idx],dp);
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n = arr.size();
          vector<vector<int>> dp(n,vector<int>(sum+1,-1));
          return helper(arr,n,0,sum,dp);
          
      }
  };
class Solution {
    public:
        int helper(vector<int>& nums, int target, int n, int i, int currSum) {
            if (i == n) {
                if (currSum == target) {
                    return 1;
                } else {
                    return 0;
                }
            }
    
            return helper(nums, target, n, i + 1, currSum + nums[i]) +
                   helper(nums, target, n, i + 1, currSum - nums[i]);
        }
        int countPartitions(vector<int>& arr, int d) {
            // Code here
            
            int sum=0,n=arr.size();
            for(int i=0;i<n;i++){
                sum+= arr[i];
            }
            
            if((sum-d) %2 !=0  || sum-abs(d)<0)return 0;
            
            int target = (sum-d)/2;
            
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
        int findTargetSumWays(vector<int>& nums, int target) {
            // int n = nums.size();
            // return helper(nums, target, n, 0, 0); // RECURSION

            return countPartitions(nums, target); // TABULATION
        }
    };
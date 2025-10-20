class Solution {
    public:
        bool helper(vector<int>& nums, int n, int idx, int sum,
                    vector<vector<int>>& dp) {
    
            if (sum == 0)
                return true;
            if (sum < 0)
                return false;
            if (idx == n)
                return false;
    
            if (dp[idx][sum] != -1)
                return dp[idx][sum];
    
            return dp[idx][sum] = helper(nums, n, idx + 1, sum - nums[idx], dp) ||
                                  helper(nums, n, idx + 1, sum, dp);
        }
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
            }
            if (sum % 2 != 0)
                return false;
            sum = sum / 2;
            vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
            return helper(nums, n, 0, sum, dp);
        }
    };
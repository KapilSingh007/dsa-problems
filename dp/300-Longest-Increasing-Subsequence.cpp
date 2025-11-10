class Solution {
    public:
        int approach1Recurrsion(vector<int>& nums, int n, int i, int last,
                                vector<vector<int>>& dp) {
    
            if (i == n)
                return 0;
    
            if (last != -1 && dp[i][last] != -1) {
                return dp[i][last];
            }
    
            int take = 0, notTake = 0;
            if (last == -1 || nums[i] > nums[last]) {
                take = 1 + approach1Recurrsion(nums, n, i + 1, i, dp);
            }
    
            notTake = approach1Recurrsion(nums, n, i + 1, last, dp);
    
            if (last != -1)
                dp[i][last] = max(take, notTake);
    
            return max(take, notTake);
        }
        int lengthOfLIS(vector<int>& nums) {
    
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n, -1));
            return approach1Recurrsion(nums, n, 0, -1, dp);
        }
    };
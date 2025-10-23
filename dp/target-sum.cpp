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
        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();
            
            return helper(nums, target, n, 0, 0);
        }
    };
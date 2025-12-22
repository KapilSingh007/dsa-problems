class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int i = 0, j = 0, k = n - 1;
    
            while (j <= k) {
                if (nums[j] == 2) {
                    swap(nums[k], nums[j]);
                    k--;
                }
                if (nums[j] == 0) {
                    swap(nums[i], nums[j]);
                    j++;
                    i++;
                }
                if (j < n && nums[j] == 1) {
                    j++;
                }
            }
        }
    };
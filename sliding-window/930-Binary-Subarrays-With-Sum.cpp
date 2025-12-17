class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int n = nums.size(), sum = 0, res = 0;
            for (int i = 0; i < n; i++) {
                sum = 0;
                for (int j = i; j < n; j++) {
                    sum += nums[j];
                    if (sum == goal) {
                        res++;
                    } else if (sum > goal) {
                        break;
                    }
                }
            }
            return res;
        }
    };
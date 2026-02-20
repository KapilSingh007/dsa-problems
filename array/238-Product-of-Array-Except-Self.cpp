class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size(), p = 1, zero = 0;
    
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    zero++;
                } else {
                    p *= nums[i];
                }
            }
    
            vector<int> res(n, 0);
            if (zero > 1) {
                return res;
            }
    
            for (int i = 0; i < n; i++) {
                if (zero == 1) {
                    if (nums[i] == 0) {
                        res[i] = p;
                    }
                } else {
    
                    res[i] = (p / nums[i]);
                }
            }
    
            return res;
        }
    };
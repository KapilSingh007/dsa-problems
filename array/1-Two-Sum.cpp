class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int t) {
            unordered_map<int, int> mp;
    
            int i = 0, n = nums.size();
    
            for (int i = 0; i < n; i++) {
                if (mp.find(t - nums[i]) != mp.end()) {
                    return {mp[t - nums[i]], i};
                } else {
                    mp[nums[i]] = i;
                }
            }
    
            return {};
        }
    };
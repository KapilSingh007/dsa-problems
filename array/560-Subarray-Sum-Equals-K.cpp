class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {


        //     // method1
        // int n = nums.size(), sum, res = 0;
        // for (int i = 0; i < n; i++) {
        //     sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         if (sum == k) {
        //             res++;
        //         }
        //     }
        // }

        // return res;

            int n = nums.size(), sum = 0, res = 0;
            unordered_map<int, int> mp;
            mp[0] = 1;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
    
                if (mp.find(sum - k) == mp.end()) {
                    mp[sum]++;
                } else {
                    res += mp[sum - k];
                    mp[sum]++;
                }
            }
    
            return res;
        }
    };
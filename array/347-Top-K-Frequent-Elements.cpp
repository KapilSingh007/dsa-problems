class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {

            //method1
            unordered_map<int, int> mp;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                mp[nums[i]]++;
            }
    
            int freq = 0;
    
            for (auto x : mp) {
                freq = max(freq, x.second);
            }
            vector<int> res;
    
            while (res.size() != k) {
                for (auto x : mp) {
                    if (x.second == freq) {
                        res.push_back(x.first);
                        if (res.size() == k) {
                            break;
                        }
                    }
                }
                freq--;
            }
    
            return res;
        }
    };
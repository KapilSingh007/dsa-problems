class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
    
            unordered_map<char, int> mp;
    
            int i = 0, j = 0, n = s.size(), res = 0;
    
            while (i < n) {
                mp[s[i]]++;
    
                while (mp[s[i]] > 1) {
                    mp[s[j]]--;
                    j++;
                }
    
                i++;
                res = max(res, i - j);
            }
            return res;
        }
    };
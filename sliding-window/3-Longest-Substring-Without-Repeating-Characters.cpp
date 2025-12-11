class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int i = 0, j = 0, res = 0, n = s.size();
            unordered_map<char, int> mp;
            while (i < n) {
                mp[s[i]]++;
                if (res < mp.size()) {
                    res = mp.size();
                }
                while (mp[s[i]] > 1) {
                    mp[s[j]]--;
                    if (mp[s[j]] == 0) {
                        mp.erase(s[j]);
                    }
                    j++;
                }
                i++;
            }
    
            return res;
        }
    };
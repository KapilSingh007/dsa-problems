class Solution {
    public:
        int characterReplacement(string s, int k) {
            int i = 0, j = 0, n = s.size(), maxf = 0, res = 0;
    
            unordered_map<char, int> mp;
    
            while (i < n) {
                mp[s[i]]++;
                maxf = max(maxf, mp[s[i]]);
    
                if ((i - j + 1 - maxf) <= k) {
                    res = max(res, i - j + 1);
                } else {
                    while ((i - j + 1 - maxf) > k) {
                        int currMax = 0;
                        mp[s[j]]--;
                        for (auto x : mp) {
                            currMax = max(currMax, x.second);
                        }
    
                        maxf = currMax;
                        j++;
                    }
                    res = max(res, i - j + 1);
                }
                i++;
            }
            return res;
        }
    };
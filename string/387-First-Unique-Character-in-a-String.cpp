class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> mp, pos;
            int res = -1;
            int n = s.size();
    
            for (int i = 0; i < n; i++) {
                mp[s[i]]++;
                if (pos.find(s[i]) == pos.end()) {
                    pos[s[i]] = i;
                }
            }
    
            for (auto x : mp) {
                if (x.second == 1 && (res == -1 || res > pos[x.first])) {
                    res = pos[x.first];
                }
            }
    
            return res;
        }
    };
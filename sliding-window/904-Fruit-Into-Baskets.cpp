class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int i = 0, j = 0, n = fruits.size(), temp = 0, res = 0;
            unordered_map<int, int> mp;
            while (i < n) {
                mp[fruits[i]]++;
                temp++;
                while (mp.size() > 2) {
                    mp[fruits[j]]--;
                    temp--;
                    if (mp[fruits[j]] == 0) {
                        mp.erase(fruits[j]);
                    }
                    j++;
                }
                res = max(res, temp);
                i++;
            }
    
            return res;
        }
    };
class Solution {
    public:
        int maxProfit(vector<int>& p) {
            int n = p.size(), ele = p[0], res = 0;
    
            for (int i = 0; i < n; i++) {
                if (p[i] >= ele) {
                    res += p[i] - ele;
                }
                ele = p[i];
            }
    
            return res;
        }
    };
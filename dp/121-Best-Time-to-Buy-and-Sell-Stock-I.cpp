class Solution {
    public:
        int maxProfit(vector<int>& p) {
            int n = p.size(), res = 0, ele = p[0];
    
            for (int i = 1; i < n; i++) {
                if (ele <= p[i]) {
                    res = max(res, p[i] - ele);
                } else {
                    ele = p[i];
                }
            }
            return res;
        }
    };
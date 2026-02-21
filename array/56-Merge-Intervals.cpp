class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& in) {
            sort(in.begin(), in.end());
    
            int n = in.size(), sz = 0;
            vector<vector<int>> res = {in[0]};
            for (int i = 0; i < n; i++) {
                if (in[i][0] <= res[sz][1] && in[i][0] >= res[sz][0]) {
                    res[sz][1] = max(res[sz][1], in[i][1]);
                } else {
                    res.push_back(in[i]);
                    sz++;
                }
            }
    
            return res;
        }
    };
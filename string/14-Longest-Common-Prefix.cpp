class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string res = "";
            int n = strs.size(), m = strs[0].size();
            if (n < 1) {
                return res;
            }
            int j = 0;
            bool cnd = true, match;
            while (cnd && j + 1 <= m) {
                char ch = strs[0][j];
                match = true;
                for (int i = 1; i < n; i++) {
                    if (strs[i].size() < j + 1 || strs[i][j] != ch) {
                        match = false;
                        cnd = false;
                        break;
                    }
                }
                if (match) {
                    res.push_back(ch);
                }
                j++;
            }
    
            return res;
        }
    };
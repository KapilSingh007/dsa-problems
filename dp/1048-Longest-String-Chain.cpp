class Solution {
    public:
        bool check(string curr, string next) {
            if (next.size() == curr.size() || next.size() - curr.size() > 1) {
                return false;
            }
            int n = curr.size(), m = next.size();
    
            int i = 0, j = 0, diff = 0;
    
            while (i < n && j < m) {
                if (curr[i] == next[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                    diff++;
                    if (diff > 1) {
                        return false;
                    }
                }
            }
    
            return true;
        }
        int approach1Recurrsion(vector<string>& words, int& n, int i, int prev,
                                vector<vector<int>>& dp) {
    
            if (i == n + 1)
                return 0;
    
            if (dp[i][prev] != -1) {
                return dp[i][prev];
            }
            int take = 0, notTake = 0;
            if (prev == 0 || check(words[prev - 1], words[i - 1])) {
                take = 1 + approach1Recurrsion(words, n, i + 1, i, dp);
            }
    
            notTake = approach1Recurrsion(words, n, i + 1, prev, dp);
    
            return dp[i][prev] = max(take, notTake);
        }
    
        int approach2Tabulation(vector<string>& words, int& n) {
    
            vector<int> dp(n, 1);
            int res = 1;
    
            for (int i = 1; i < n; i++) {
    
                for (int j = 0; j < i; j++) {
                    if (check(words[j], words[i]) && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
    
                res = max(res, dp[i]);
            }
    
            return res;
        }
        int longestStrChain(vector<string>& words) {
            sort(words.begin(), words.end(), [](const string& a, const string& b) {
                return a.size() < b.size();
            });
    
            int n = words.size();
    
            // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
            // return approach1Recurrsion(words, n, 1, 0, dp);
    
            return approach2Tabulation(words, n);
        }
    };
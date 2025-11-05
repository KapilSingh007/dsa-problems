class Solution {
    public:
        int approach1Recurrsion(string& word1, string& word2, int& n1, int& n2,
                                int i, int j, vector<vector<int>>& dp) {
    
            if (i == 0) {
                return j;
            }
    
            if (j == 0) {
                return i;
            }
    
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
    
            if (word1[i - 1] != word2[j - 1]) {
                return dp[i][j] = 1 + min({approach1Recurrsion(word1, word2, n1, n2,
                                                               i, j - 1, dp),
                                           approach1Recurrsion(word1, word2, n1, n2,
                                                               i - 1, j, dp),
                                           approach1Recurrsion(word1, word2, n1, n2,
                                                               i - 1, j - 1, dp)});
            } else {
                return dp[i][j] = approach1Recurrsion(word1, word2, n1, n2, i - 1,
                                                      j - 1, dp);
            }
        }
        int minDistance(string word1, string word2) {
            int n1 = word1.size(), n2 = word2.size();
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
            return approach1Recurrsion(word1, word2, n1, n2, n1, n2, dp);
        }
    };
class Solution {
    public:
        vector<string> recurrsion(string& s1, string& s2, int& n1, int& n2, int i,
                                  int j, vector<vector<vector<string>>>& dp1,
                                  vector<vector<int>>& dp2) {
            if (i == -1 || j == -1) {
                return {};
            }
    
            if (dp2[i][j]) {
                return dp1[i][j];
            }
    
            if (s1[i] == s2[j]) {
                vector<string> vt =
                    recurrsion(s1, s2, n1, n2, i - 1, j - 1, dp1, dp2);
    
                if (vt.empty()) {
                    string s = "";
                    s.push_back(s1[i]);
                    dp2[i][j] = 1;
                    return dp1[i][j] = {s};
                }
    
                for (int k = 0; k < vt.size(); k++) {
                    vt[k].push_back(s1[i]);
                }
    
                dp2[i][j] = 1;
                return dp1[i][j] = vt;
            } else {
                vector<string> vt1 = recurrsion(s1, s2, n1, n2, i - 1, j, dp1, dp2);
                vector<string> vt2 = recurrsion(s1, s2, n1, n2, i, j - 1, dp1, dp2);
    
                if (vt1.empty()) {
                    dp2[i][j] = 1;
                    return dp1[i][j] = vt2;
                }
                if (vt2.empty()) {
                    dp2[i][j] = 1;
                    return dp1[i][j] = vt1;
                }
                if (vt1[0].size() > vt2[0].size()) {
                    dp2[i][j] = 1;
                    return dp1[i][j] = vt1;
                } else if (vt1[0].size() < vt2[0].size()) {
                    dp2[i][j] = 1;
                    return dp1[i][j] = vt2;
                } else {
                    for (auto k : vt2)
                        vt1.push_back(k);
    
                    dp2[i][j] = 1;
                    return dp1[i][j] = vt1;
                }
            }
        }
        vector<string> method1(string& s1, string& s2){
    
            int n1 = s1.size(), n2 = s2.size();
    
            vector<vector<vector<string>>> dp1(n1, vector<vector<string>>(n2));
            vector<vector<int>> dp2(n1, vector<int>(n2, 0));
    
            vector<string> vt =
                recurrsion(s1, s2, n1, n2, n1 - 1, n2 - 1, dp1, dp2);
    
            set<string> st(vt.begin(), vt.end());
    
            vector<string> res(st.begin(), st.end());
    
            return res;
        }
        
    vector<string> method2(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
    
        vector<vector<vector<string>>> dp(
            n1 + 1, vector<vector<string>>(n2 + 1, vector<string>()));
    
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    vector<string> vt = dp[i - 1][j - 1];
                    if (vt.empty()) {
                        string s = "";
                        s.push_back(s1[i-1]);
                        dp[i][j] = {s};
                    } else {
                        for (int k = 0; k < vt.size(); k++) {
                            vt[k].push_back(s1[i - 1]);
                        }
                        dp[i][j] = vt;
                    }
                } else {
                    if (dp[i - 1][j].empty()) {
                        dp[i][j] = dp[i][j - 1];
                    } else if (dp[i][j - 1].empty()) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        if (dp[i - 1][j][0].size() > dp[i][j - 1][0].size()) {
                            dp[i][j] = dp[i - 1][j];
                        } else if (dp[i - 1][j][0].size() <
                                   dp[i][j - 1][0].size()) {
                            dp[i][j] = dp[i][j - 1];
                        } else {
                            vector<string> vt1 = dp[i - 1][j];
                            vector<string> vt2 = dp[i][j - 1];
    
                            for (int k = 0; k < vt2.size(); k++) {
                                vt1.push_back(vt2[k]);
                            }
                            dp[i][j] = vt1;
                        }
                    }
                }
            }
        }
        
        vector<string> vt =  dp[n1][n2];
        set<string> st(vt.begin(), vt.end());
    
            vector<string> res(st.begin(), st.end());
    
            return res;
    }
        vector<string> allLCS(string& s1, string& s2) {
            // Code here
            // return method1(s1,s2);
            
            return method2(s1,s2);
        }
    };
    
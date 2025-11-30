class Solution {
    public:
        bool createGraph(string s1, string s2, map<char, vector<char>>& mp,
                         map<char, bool>& vis, map<char, bool>& inRecurr) {
    
            int i = 0, j = 0, n = s1.size(), m = s2.size();
    
            while (i < n && j < m) {
    
                if (s1[i] != s2[j]) {
                    mp[s1[i]].push_back(s2[j]);
                    return false;
                }
    
                i++;
                j++;
            }
    
            return n > m;
        }
    
        bool dfs(map<char, vector<char>>& mp, map<char, bool>& vis,
                 map<char, bool>& inRecurr, string& res, char currNode) {
    
            vis[currNode] = true;
            inRecurr[currNode] = true;
    
            for (char x : mp[currNode]) {
                if (!vis[x]) {
                    if (dfs(mp, vis, inRecurr, res, x)) {
                        return true;
                    }
                } else if (inRecurr[x]) {
                    return true;
                }
            }
    
            inRecurr[currNode] = false;
            res.insert(res.begin(), currNode);
            return false;
        }
        string findOrder(vector<string>& words) {
            // code here
    
            int n = words.size();
            map<char, vector<char>> mp;
            map<char, bool> vis, inRecurr;
            string res;
            for (int i = 0; i <= n - 2; i++) {
                if (createGraph(words[i], words[i + 1], mp, vis, inRecurr)) {
                    return res;
                }
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < words[i].size(); j++) {
                    vis[words[i][j]] = false;
                    inRecurr[words[i][j]] = false;
                }
            }
    
            // for (auto x : vis) {
            //     cout << x.first << " " << x.second << endl;
            // }
    
            for (auto x : vis) {
                if (!vis[x.first] && dfs(mp, vis, inRecurr, res, x.first)) {
                    res.clear();
                    return res;
                }
            }
    
            return res;
        }
    };


    // testcase1: baa abcd abca cab cad

    // testcase2: dddc a ad ab b be cd cded

    // testcase3: abc ab
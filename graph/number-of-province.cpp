class Solution {
    public:
        void dfs(vector<vector<int>>& adj, vector<int>& vis, int idx) {
            for (auto x : adj[idx]) {
                if (!vis[x]) {
                    vis[x] = 1;
                    dfs(adj, vis, x);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
    
            int m = isConnected.size();
            vector<vector<int>> adj(m);
            vector<int> vis(m, 0);
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (i != j && isConnected[i][j] == 1) {
                        adj[i].push_back(j);
                    }
                }
            }
    
            int res = 0;
            for (int i = 0; i < m; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    res++;
                    dfs(adj, vis, i);
                }
            }
    
            return res;
        }
    };
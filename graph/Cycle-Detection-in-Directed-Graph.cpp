class Solution {
    public:
        vector<vector<int>> createAdj(vector<vector<int>>& edges, int V) {
            int n = edges.size();
    
            vector<vector<int>> adj(V, vector<int>());
    
            for (int i = 0; i < n; i++) {
                adj[edges[i][0]].push_back(edges[i][1]);
            }
    
            return adj;
        }
    
        bool dfs(vector<vector<int>>& adj, int V, vector<int>& vis,
                 vector<int>& inRecurr, int currNode) {
    
            vis[currNode] = 1;
            inRecurr[currNode] = 1;
    
            for (int x : adj[currNode]) {
                if (!vis[x]) {
                    if (dfs(adj, V, vis, inRecurr, x)) {
                        return true;
                    }
                } else if (inRecurr[x] == 1) {
                    return true;
                }
            }
    
            inRecurr[currNode] = 0;
            return false;
        }
        bool isCyclic(int V, vector<vector<int>>& edges) {
            // code here
            vector<int> vis(V, 0), inRecurr(V, 0);
            vector<vector<int>> adj = createAdj(edges, V);
            for (int i = 0; i < V; i++) {
    
                if (!vis[i] && dfs(adj, V, vis, inRecurr, i)) {
                    return true;
                }
            }
    
            return false;
        }
    };
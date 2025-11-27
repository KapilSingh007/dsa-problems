class Solution {
    public:
        vector<vector<int>> createAdj(vector<vector<int>>& edges,int V) {
            int n = edges.size();
    
            vector<vector<int>> adj(V, vector<int>());
    
            for (int i = 0; i < n; i++) {
                adj[edges[i][0]].push_back(edges[i][1]);
            }
            
            return adj;
        }
    
        void dfs(vector<vector<int>>& adj, int currNode, vector<int>& res,
                 vector<int>& vis) {
    
            vis[currNode] = 1;
    
            for (int x : adj[currNode]) {
                if (!vis[x]) {
                    dfs(adj, x, res, vis);
                }
            }
    
            res.insert(res.begin(), currNode);
        }
        vector<int> topoSort(int V, vector<vector<int>>& edges) {
            // code here
    
            vector<int> res, vis(V, 0);
    
            vector<vector<int>> adj = createAdj(edges,V);
    
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    dfs(adj, i, res, vis);
                }
            }
    
            return res;
        }
    };
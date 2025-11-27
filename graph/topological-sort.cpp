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
    
        void approach1DFS(int V, vector<vector<int>>& adj, vector<int>& res) {
    
            vector<int> vis(V, 0);
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    dfs(adj, i, res, vis);
                }
            }
        }
    
        void approach1BFS(int V, vector<vector<int>>& edges,
                          vector<vector<int>>& adj, vector<int>& res) {
    
            vector<int> indegree(V, 0);
            int e = edges.size(), node;
            queue<int> q;
            for (int i = 0; i < e; i++) {
                indegree[edges[i][1]]++;
            }
    
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
    
            while (!q.empty()) {
                node = q.front();
                q.pop();
    
                res.push_back(node);
    
                for (int x : adj[node]) {
    
                    if (--indegree[x] == 0) {
                        q.push(x);
                    }
                }
            }
        }
        vector<int> topoSort(int V, vector<vector<int>>& edges) {
            // code here
    
            vector<int> res;
    
            vector<vector<int>> adj = createAdj(edges, V);
    
            // approach1DFS(V, adj, res);
    
            approach1BFS(V, edges, adj, res);
    
            return res;
        }
    };
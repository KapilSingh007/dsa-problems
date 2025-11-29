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
    
        bool dfsHelper(vector<vector<int>>& adj, int V, vector<int>& vis,
                       vector<int>& inRecurr, int currNode) {
    
            vis[currNode] = 1;
            inRecurr[currNode] = 1;
    
            for (int x : adj[currNode]) {
                if (!vis[x]) {
                    if (dfsHelper(adj, V, vis, inRecurr, x)) {
                        return true;
                    }
                } else if (inRecurr[x] == 1) {
                    return true;
                }
            }
    
            inRecurr[currNode] = 0;
            return false;
        }
    
        bool dfs(vector<vector<int>> adj, int V) {
            vector<int> vis(V, 0), inRecurr(V, 0);
            for (int i = 0; i < V; i++) {
    
                if (!vis[i] && dfsHelper(adj, V, vis, inRecurr, i)) {
                    return true;
                }
            }
    
            return false;
        }
    
        bool bfs(vector<vector<int>>& edges, vector<vector<int>> adj, int V) {
    
            int n = edges.size(), currNode;
            vector<int> indegree(V, 0), res;
            queue<int> q;
    
            for (int i = 0; i < n; i++) {
                indegree[edges[i][1]]++;
            }
    
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                    res.push_back(i);
                }
            }
    
            while (!q.empty()) {
                currNode = q.front();
                q.pop();
    
                for (int x : adj[currNode]) {
                    if (--indegree[x] == 0) {
                        q.push(x);
                        res.push_back(x);
                    }
                }
            }
    
            return res.size() != V;
        }
    
        bool isCyclic(int V, vector<vector<int>>& edges) {
            // code here
    
            vector<vector<int>> adj = createAdj(edges, V);
            // return dfs(adj, V);
    
            return bfs(edges, adj, V);
        }
    };
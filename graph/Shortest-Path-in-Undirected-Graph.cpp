class Solution {
    public:
        vector<vector<int>> createAdj(int V, vector<vector<int>>& edges) {
            vector<vector<int>> adj(V, vector<int>());
    
            for (vector<int> x : edges) {
                adj[x[0]].push_back(x[1]);
                adj[x[1]].push_back(x[0]);
            }
    
            return adj;
        }
        vector<int> approach1BFS(int V, vector<vector<int>>& edges, int src) {
            vector<vector<int>> adj = createAdj(V, edges);
            vector<int> res(V, -1);
            int currNode, sz, dist = 0;
            res[src] = dist;
    
            queue<int> q;
            q.push(src);
    
            while (!q.empty()) {
                sz = q.size();
                dist++;
                while (sz--) {
                    currNode = q.front();
                    q.pop();
                    for (int x : adj[currNode]) {
                        if (res[x] == -1) {
                            res[x] = dist;
                            q.push(x);
                        }
                    }
                }
            }
            
            return res;
        }
        vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
            // code here
            vector<int> res(V, -1);
    
            return approach1BFS(V, edges, src);
        }
    };
    
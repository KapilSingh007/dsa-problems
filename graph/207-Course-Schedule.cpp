class Solution {
    public:
        vector<vector<int>> createAdj(int n, vector<vector<int>>& prerequisites) {
    
            vector<vector<int>> adj(n, vector<int>());
            int sz = prerequisites.size();
            for (int i = 0; i < sz; i++) {
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
    
            return adj;
        }
    
        bool dfsHelper(vector<vector<int>> adj, int V, vector<int>& vis,
                       vector<int>& inRecurr, int currNode) {
    
            vis[currNode] = 1;
            inRecurr[currNode] = 1;
    
            for (int x : adj[currNode]) {
                if (!vis[x]) {
                    if (dfsHelper(adj, V, vis, inRecurr, x)) {
                        return true;
                    }
                } else if (inRecurr[x]) {
                    return true;
                }
            }
    
            inRecurr[currNode] = 0;
            return false;
        }
        bool approach1DFS(vector<vector<int>> adj, int V) {
    
            vector<int> vis(V, 0), inRecurr(V, 0);
    
            for (int i = 0; i < V; i++) {
                if (!vis[i] && dfsHelper(adj, V, vis, inRecurr, i)) {
                    return false;
                }
            }
    
            return true;
        }
    
        bool approach2BFS(vector<vector<int>>& prerequisites,
                          vector<vector<int>> adj, int V) {
    
            vector<int> indegree(V, 0);
            int n = prerequisites.size();
            queue<int> q;
            int resSz = 0, currNode;
            for (int i = 0; i < n; i++) {
                indegree[prerequisites[i][1]]++;
            }
    
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                    resSz++;
                }
            }
    
            while (!q.empty()) {
                currNode = q.front();
                q.pop();
    
                for (int x : adj[currNode]) {
                    if (--indegree[x] == 0) {
                        q.push(x);
                        resSz++;
                    }
                }
            }
           
            return resSz == V;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj = createAdj(numCourses, prerequisites);
    
            // DFS will give result but it will give TLE because of recursion stack space
            // return approach1DFS(adj, numCourses);


            // Thats why we use BFS to detect cycle in a directed graph
            return approach2BFS(prerequisites, adj, numCourses);
        }
    };
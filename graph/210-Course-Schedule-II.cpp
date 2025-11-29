class Solution {
    public:
        vector<vector<int>> createAdj(int n, vector<vector<int>>& prerequisites) {
    
            vector<vector<int>> adj(n, vector<int>());
            int sz = prerequisites.size();
            for (int i = 0; i < sz; i++) {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
    
            return adj;
        }
    
        vector<int> approach1BFS(vector<vector<int>>& prerequisites,
                                 vector<vector<int>> adj, int V) {
    
            vector<int> indegree(V, 0), res, temp;
            int n = prerequisites.size();
            queue<int> q;
            int currNode;
            for (int i = 0; i < n; i++) {
                indegree[prerequisites[i][0]]++;
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
    
            return res.size() == V ? res : temp;
        }
    
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj = createAdj(numCourses, prerequisites);
    
            return approach1BFS(prerequisites, adj, numCourses);
        }
    };
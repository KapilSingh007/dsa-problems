class Solution {
    public:
        bool dfsHelper(vector<vector<int>>& graph, int currNode, int currColor,
                       vector<int>& vis) {
    
            vis[currNode] = currColor;
    
            for (int x : graph[currNode]) {
                if (vis[x] == -1 && !dfsHelper(graph, x, !currColor, vis)) {
                    return false;
                }
    
                if (vis[x] == currColor) {
                    return false;
                }
            }
    
            return true;
        }
    
        bool approach1DFS(vector<vector<int>>& graph, int n, vector<int>& vis) {
            for (int i = 0; i < n; i++) {
                if (vis[i] == -1 && !dfsHelper(graph, i, 0, vis)) {
                    return false;
                }
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> vis(n, -1);
    
            return approach1DFS(graph, n, vis);
        }
    };
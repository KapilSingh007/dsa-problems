class Solution {
    public:
        bool dfsHelper(vector<vector<int>>& graph, vector<int>& vis,
                       vector<int>& inRecurr, int currNode) {
            vis[currNode] = 1;
            inRecurr[currNode] = 1;
    
            for (int x : graph[currNode]) {
    
                if (!vis[x]) {
                    if (dfsHelper(graph, vis, inRecurr, x)) {
                        return true;
                    }
                } else if (inRecurr[x]) {
                    return true;
                }
            }
            inRecurr[currNode] = 0;
            return false;
        }
        vector<int> approach1DFS(vector<vector<int>>& graph, int v) {
    
            vector<int> vis(v, 0), inRecurr(v, 0), res;
    
            for (int i = 0; i < v; i++) {
                if (!vis[i]) {
                    dfsHelper(graph, vis, inRecurr, i);
                }
            }
            for (int i = 0; i < v; i++) {
                if (inRecurr[i] == 0) {
                    res.push_back(i);
                }
            }
    
            return res;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
            int v = graph.size();
    
            return approach1DFS(graph, v);
        }
    };
class Solution {
    public:
        vector<vector<pair<int, int>>> createAdj(int V,
                                                 vector<vector<int>>& edges) {
            vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
    
            for (vector<int> x : edges) {
                adj[x[0]].push_back({x[1], x[2]});
                adj[x[1]].push_back({x[0], x[2]});
            }
    
            return adj;
        }
    
        vector<int> approach1PQ(vector<vector<pair<int, int>>> adj, int V,
                                int src) {
    
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                q;
            pair<int, int> currNode;
            vector<int> res(V, INT_MAX);
    
            q.push({0, src});
            res[src] = 0;
    
            while (!q.empty()) {
                currNode = q.top();
                q.pop();
    
                for (pair<int, int> x : adj[currNode.second]) {
                    if (res[x.first] == INT_MAX ||
                        res[x.first] > res[currNode.second] + x.second) {
                        res[x.first] = res[currNode.second] + x.second;
                        q.push({res[x.first], x.first});
                    }
                }
            }
    
            return res;
        }
    
        vector<int> approach1Set(vector<vector<pair<int, int>>> adj, int V,
                                 int src) {
            set<pair<int, int>> st;
            pair<int, int> currNode;
            vector<int> res(V, INT_MAX);
    
            st.insert({0, src});
            res[src] = 0;
    
            while (!st.empty()) {
                currNode = *st.begin();
                st.erase(currNode);
    
                for (pair<int, int> x : adj[currNode.second]) {
                    if (res[x.first] == INT_MAX) {
                        res[x.first] = res[currNode.second] + x.second;
                        st.insert({res[x.first], x.first});
                    }
                    if (res[x.first] > res[currNode.second] + x.second) {
                        st.erase({res[x.first], x.first});
                        res[x.first] = res[currNode.second] + x.second;
                        st.insert({res[x.first], x.first});
                    }
                }
            }
    
            return res;
        }
        vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
            // Code here
            vector<vector<pair<int, int>>> adj = createAdj(V, edges);
            // return approach1PQ(adj, V, src);
    
            return approach1Set(adj, V, src);
        }
    };
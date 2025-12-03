// User function Template for C++
class Solution {
    public:
    vector<vector<pair<int,int>>> createAdj(int V, vector<vector<int>>& edges) {
          vector<vector<pair<int,int>>> adj(V, vector<pair<int,int>>());
  
          for (vector<int> x : edges) {
              adj[x[0]].push_back({x[1],x[2]});
             
          }
  
          return adj;
      }
      
      vector<int> approach1BFS(int V, vector<vector<int>>& edges, int src) {
          vector<vector<pair<int,int>>> adj = createAdj(V, edges);
          vector<int> res(V, -1);
          int currNode, sz;
          res[src] = 0;
  
          queue<int> q;
          q.push(src);
  
          while (!q.empty()) {
              sz = q.size();
          
              while (sz--) {
                  currNode = q.front();
                  q.pop();
                  for (pair<int,int> x : adj[currNode]) {
                      if (res[x.first] == -1 || res[x.first]>res[currNode] + x.second) {
                          res[x.first] = res[currNode] + x.second;
                          q.push(x.first);
                      }
                  }
              }
          }
  
          return res;
      }
  
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          // code here
          return approach1BFS(V, edges, 0);
      }
  };
  
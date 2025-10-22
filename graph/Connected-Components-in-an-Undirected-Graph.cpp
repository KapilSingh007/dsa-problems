
class Solution {
    public:
      
      void dfs(vector<vector<int>>& adj,vector<int>& vis, vector<int>& temp,int node){
          
          temp.push_back(node);
          vis[node]=1;
          for(int i=0;i<adj[node].size();i++){
              if(!vis[adj[node][i]]){
              dfs(adj,vis,temp,adj[node][i]);
              }
          }
      }
      vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
          // code here
          
          int e = edges.size();
          vector<vector<int>> adj(V),res;
          for(int i=0;i<e;i++){
              adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
          }
          
          
          vector<int> vis(V,0);
              vector<int> temp;
          
          for(int i=0;i<V;i++){
              if(!vis[i]){
              temp.clear();
              dfs(adj,vis,temp,i);
              res.push_back(temp);
              }
          }
          
          return res;
      }
  };
class Solution {
    public:
    
      vector<vector<int>> creationOfAdjList(int V,vector<vector<int>>& edges){
          vector<vector<int>> adj(V);
          
          int n=edges.size();
          for(int i=0;i<n;i++){
              adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
          }
          return adj;
      }
      bool bfs(int V, vector<vector<int>>& edges){
          vector<vector<int>> adj = creationOfAdjList(V,edges);
          vector<int> vis(V,0);
          queue<pair<int,int>> q;
          int qCurrSz , node, parent, childArrsize;
          
          for(int i=0;i<V;i++){
              if(vis[i]){
                  continue;
              }
              q.push({i,-1});
              vis[i] = 1;
              
              while(!q.empty()){
                  qCurrSz = q.size();
                  
                  while(qCurrSz--){
                      node = q.front().first;
                      parent = q.front().second;
                      q.pop();
                      
                      childArrsize = adj[node].size();
                      for(int j=0;j<childArrsize;j++){
                          if(adj[node][j] == parent){
                              continue;
                          }
                          if(vis[adj[node][j]]){
                              return true;
                          }
                          
                          q.push({adj[node][j],node});
                          vis[adj[node][j]] = 1;
                      }
                  }
              }
          }
          return false;
      }
      
      bool dfsHelper(int node,int parent,vector<vector<int>>& adj,vector<int>& vis){
          vis[node] =1;
          int sz = adj[node].size();
          
          for(int i=0;i<sz;i++){
              if(adj[node][i] != parent){
                  
                  if(vis[adj[node][i]]){
                      return true;
                  }
                  
                  if(dfsHelper(adj[node][i],node,adj,vis)){
                      return true;
                  }
              }
          }
          
          return false;
      }
      bool dfs(int V, vector<vector<int>>& edges){
          vector<vector<int>> adj = creationOfAdjList(V,edges);
          vector<int> vis(V,0);
          for(int i=0;i<V;i++) {
              if(vis[i]){
                  continue;
              } 
              
              if(dfsHelper(i,-1,adj,vis)){
                  return true;
              }
          }
          
          
          return false;
      }
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          
          // return bfs(V,edges);
          return dfs(V,edges);
          
      }
  };
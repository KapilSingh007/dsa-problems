// User function Template for C++

class Solution {
    public:
        vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
        void dfs(vector<vector<int>>& grid, int& n, int& m,
                 vector<vector<int>>& vis, int i, int j, int& ori, int& orj,
                 vector<pair<int, int>>& t) {
    
            vis[i][j] = 1;
            t.push_back({i - ori, j - orj});
    
            for (int k = 0; k < 4; k++) {
                int r = i + row[k], c = j + col[k];
    
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] &&
                    grid[r][c] == 1) {
                    dfs(grid, n, m, vis, r, c, ori, orj, t);
                }
            }
        }
        int countDistinctIslands(vector<vector<int>>& grid) {
            // code here
            int n = grid.size(), m = grid[0].size();
    
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            vector<pair<int, int>> t;
            set<vector<pair<int, int>>> st;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t.clear();
                    if (!vis[i][j] && grid[i][j] == 1) {
                        dfs(grid, n, m, vis, i, j, i, j, t);
                        if (t.size() > 0) {
                            st.insert(t);
                        }
                    }
                }
            }
    
            return st.size();
        }
    };
    
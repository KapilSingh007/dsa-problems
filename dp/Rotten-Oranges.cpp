class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<int> col = {0, 1, 0, -1}, row = {-1, 0, 1, 0};
            queue<pair<int, int>> q;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        q.push({i, j});
                    }
                }
            }
    
            int res = 0, currSize, nr, nc;
            pair<int, int> currIdx;
            bool found = false;
            while (!q.empty()) {
                currSize = q.size();
                found = false;
                while (currSize--) {
                    currIdx = q.front();
                    q.pop();
    
                    for (int i = 0; i < 4; i++) {
                        nr = currIdx.first + row[i];
                        nc = currIdx.second + col[i];
    
                        if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                            grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                            found = true;
                        }
                    }
                }
    
                res = found ? res + 1 : res;
                // res++;
            }
    
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
    
            return res;
        }
    };
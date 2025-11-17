class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m = mat.size(), n = mat[0].size(), qSz;
            vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
    
            vector<vector<int>> dist(m, vector<int>(n, -1));
            queue<pair<int, int>> q;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 0) {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
    
            while (!q.empty()) {
                qSz = q.size();
                while (qSz--) {
                    int r = q.front().first, c = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nr = r + row[i], nc = c + col[i];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                            mat[nr][nc] == 1 && dist[nr][nc] == -1) {
                            dist[nr][nc] = dist[r][c] + 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
    
            return dist;
        }
    };
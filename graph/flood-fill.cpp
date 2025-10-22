class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                      int color) {
            if (image[sr][sc] == color)
                return image;
            vector<int> col = {0, 1, 0, -1}, row = {-1, 0, 1, 0};
            int m = image.size(), n = image[0].size(), currSize, nr, nc,
                startColor = image[sr][sc];
    
            queue<pair<int, int>> q;
            pair<int, int> currIdx;
    
            q.push({sr, sc});
    
            while (!q.empty()) {
                currSize = q.size();
    
                while (currSize--) {
                    currIdx = q.front();
                    q.pop();
    
                    for (int i = 0; i < 4; i++) {
                        nr = currIdx.first + row[i];
                        nc = currIdx.second + col[i];
    
                        if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                            image[nr][nc] == startColor) {
                            q.push({nr, nc});
                        }
                    }
    
                    image[currIdx.first][currIdx.second] = color;
                }
            }
    
            return image;
        }
    };
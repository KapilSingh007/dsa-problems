class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& h) {
            vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
    
            int r, c, n = h.size(), m = h[0].size(), currDist, nr, nc;
    
            priority_queue<pair<int, pair<int, int>>,
                           vector<pair<int, pair<int, int>>>,
                           greater<pair<int, pair<int, int>>>>
                pq;
    
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    
            pq.push({0, {0, 0}});
            dist[0][0] = 0;
    
            while (!pq.empty()) {
                r = pq.top().second.first;
                c = pq.top().second.second;
                currDist = pq.top().first;
                pq.pop();
    
                for (int i = 0; i < 4; i++) {
                    nr = r + row[i];
                    nc = c + col[i];
    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        dist[nr][nc] > max(abs(h[nr][nc] - h[r][c]), currDist)) {
                        dist[nr][nc] = max(abs(h[nr][nc] - h[r][c]), currDist);
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
            return dist[n - 1][m - 1];
        }
    };
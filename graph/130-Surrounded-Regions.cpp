class Solution {
    public:
        vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
        
        void markVisited(vector<vector<char>>& board, vector<vector<int>>& vis,
                         int& m, int& n, int i, int j) {
            vis[i][j] = 1;
    
            for (int k = 0; k < 4; k++) {
                int r = i + row[k], c = j + col[k];
                if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] &&
                    board[r][c] == 'O') {
                    markVisited(board, vis, m, n, r, c);
                }
            }
        }
    
        void solve(vector<vector<char>>& board) {
    
            int m = board.size(), n = board[0].size();
            vector<vector<int>> vis(m, vector<int>(n, 0));
    
            for (int i = 0; i < m; i++) {
                if (!vis[i][0] && board[i][0] == 'O') {
                    markVisited(board, vis, m, n, i, 0);
                }
    
                if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                    markVisited(board, vis, m, n, i, n - 1);
                }
            }
    
            for (int i = 0; i < n; i++) {
                if (!vis[0][i] && board[0][i] == 'O') {
                    markVisited(board, vis, m, n, 0, i);
                }
    
                if (!vis[m - 1][i] && board[m - 1][i] == 'O') {
                    markVisited(board, vis, m, n, m - 1, i);
                }
            }
    
            for (int i = 1; i <= m - 2; i++) {
                for (int j = 1; j <= n - 2; j++) {
                    if (!vis[i][j] && board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    };
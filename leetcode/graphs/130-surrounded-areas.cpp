class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y, int row, int col){

        board[x][y] = 'S';

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx < row && ny < col && board[nx][ny] == 'O'){
                dfs(board, nx, ny, row, col);
            }
        }

        return ;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i ++){
            // traverse through row
            if(board[i][0] == 'O'){
                dfs(board, i, 0, m, n);
            }
            if(board[i][n - 1] == 'O'){
                dfs(board, i, n - 1, m, n);
            }
        }

        for(int i = 0; i < n; i++){
            // traverse through column
            if(board[0][i] == 'O'){
                dfs(board, 0, i, m, n);
            }
            if(board[m - 1][i] == 'O'){
                dfs(board, m - 1, i, m, n);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

        return ;
    }
};
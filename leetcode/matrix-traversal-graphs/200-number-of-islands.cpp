class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x, int y, int row, int col, unordered_map<string, bool> &visited){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        grid[x][y] = 'x';
        string key = to_string(x) + "_" + to_string(y);
        visited[key] = true;

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == '1'){
                dfs(grid, nx, ny, row, col, visited);
            }
        }

        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0, m = grid.size(), n = grid[0].size();
        unordered_map<string, bool> visited;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                string key = to_string(i) + "_" + to_string(j);
                if(!visited[key] && grid[i][j] == '1'){
                    dfs(grid, i, j , m, n, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, - 1, 1};
        int m = image.size(), n = image[0].size();
        // push to queue
        q.push({sr, sc});

        // current color
        int currentColor = image[sr][sc];
        if(currentColor == color){
            return image;
        }

        while(!q.empty()){
            pair<int, int> f = q.front();
            q.pop();
            int x = f.first, y = f.second;
            image[x][y] = color;
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                // if index is within bounds and image poitns is current color
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == currentColor){
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};
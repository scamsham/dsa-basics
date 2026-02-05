/*
    Level: HARD
    Given an m x n integers matrix, return the length of the longest increasing path in matrix.
    From each cell, you can either move in four directions: left, right, up, or down.
    You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
    https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/1908775181/
*/

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        // tricky to find the source.
        int m = matrix.size(), n = matrix[0].size(), length = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first, y = p.second;
                    int value = matrix[x][y];
                    visited[x][y] = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > value)
                        {
                            if (visited[nx][ny])
                            {
                                dp[x][y] = dp[nx][ny] + 1;
                            }
                            else
                            {
                                q.push({nx, ny});
                                dp[nx][ny] = 1;
                            }
                        }
                    }
                }
                length = max(length, dp[i][j]);
            }
        }
        return length + 1;
    }
};
/*
    Level: HARD
    Given an m x n integers matrix, return the length of the longest increasing path in matrix.
    From each cell, you can either move in four directions: left, right, up, or down.
    You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
    https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

class Solution
{
public:
    int dfs(vector<vector<int>> &matrix, int x, int y, int row, int col, vector<vector<int>> &dp)
    {
        if (dp[x][y] != 0)
        {
            return dp[x][y];
        }

        int maxPath = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && matrix[nx][ny] > matrix[x][y])
            {
                maxPath = max(maxPath, 1 + dfs(matrix, nx, ny, row, col, dp));
            }
        }

        return dp[x][y] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (matrix.empty())
        {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result = max(result, dfs(matrix, i, j, m, n, dp));
            }
        }

        return result;
    }
};
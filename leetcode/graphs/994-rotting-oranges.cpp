/*
https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // we use bfs here since we want to compute time parallely
        // return queue size will tell us the time
        // dfs implementation is incorrect
        // because by the time it reaches an orange to mark it as rotten, it may already have gotten rotten.

        int m = grid.size(), n = grid[0].size(), freshOranges = 0;
        queue<pair<int, int>> q;

        // push all the rotten oranges indices in the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }
        if (freshOranges == 0)
        {
            return 0;
        }
        if (q.empty())
        {
            return -1;
        }
        // this is to let us know that level is completed
        q.push({-1, -1});

        int time = 0;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == -1 && p.second == -1)
            {
                // if q is empty
                if (q.empty())
                {
                    break;
                }
                else
                {
                    time++;
                    q.push({-1, -1});
                }
            }
            else
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = p.first + dx[k];
                    int ny = p.second + dy[k];
                    // boundary check and orange freshness check
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        freshOranges--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return freshOranges == 0 ? time : -1;
    }
};
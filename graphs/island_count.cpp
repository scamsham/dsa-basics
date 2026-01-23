#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, const int M, const int N, vector<vector<bool>> &visited, int &count, int &size)
{
    if (i < 0 || j < 0 || i >= M || j >= N)
        return;

    if (grid[i][j] == 0)
        return;

    if (visited[i][j])
    {
        return;
    }

    visited[i][j] = true;
    size++;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int k = 0; k < 4; k++)
    {
        int idx = i + dx[k];
        int idy = j + dy[k];

        dfs(grid, idx, idy, M, N, visited, count, size);
    }
}

int largest_island(vector<vector<int>> grid)
{
    // return the size of largest island in grid
    int M = grid.size();
    int N = grid[0].size();

    vector<vector<bool>> visited(M, vector<bool>(N, false));

    int count = 0;
    int size = 0;
    int maxSize = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                size = 0;
                dfs(grid, i, j, M, N, visited, count, size);
                maxSize = max(size, maxSize);
            }
        }
    }

    return maxSize;
}

int main()
{
    vector<vector<int>> g = {
        {1, 1, 0},
        {0, 0, 1},
        {0, 1, 1},
        {1, 0, 1},
        {1, 0, 1}};
    cout << largest_island(g);

    return 0;
}
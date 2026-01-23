#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, int M, int N, vector<vector<bool>> &visited)
{
    visited[i][j] = true;

    int current_size = 1;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 1 && !visited[nx][ny])
        {
            current_size += dfs(grid, nx, ny, M, N, visited);
        }
    }
    return current_size;
}

int largest_island(vector<vector<int>> grid)
{
    int M = grid.size();
    int N = grid[0].size();

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    int largest = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                int size = dfs(grid, i, j, M, N, visited);
                largest = max(largest, size);
            }
        }
    }
    return largest;
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
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;

// dijkshtras
class Node
{
public:
    int x, y;
    int dist;

    Node(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

// comparator should return boolean value, indicating whether the element passed as first argument is considered to go before the second in the specific strict weak ordering
class Compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int>> grid)
{

    //----------------/////
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = 0;

    vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX));

    dist[i][j] = grid[0][0];
    set<Node, Compare> s;
    s.insert(Node(i, j, dist[0][0]));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!s.empty())
    {
        // get the node that is having smallest dist
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        s.erase(it);

        // update the neigbours of this node and push them in the set
        for (int k = 0; k < 4; k++)
        {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 and nx < m and ny >= 0 and ny < n and dist[nx][ny] > cd + grid[nx][ny])
            {
                // remove the old node from the set
                Node temp(nx, ny, dist[nx][ny]);
                if (s.find(temp) != s.end())
                {
                    s.erase(s.find(temp));
                }
                // insert the new node in the set
                int nd = grid[nx][ny] + cd;
                dist[nx][ny] = nd;
                s.insert(Node(nx, ny, nd));
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return dist[m - 1][n - 1];
}

void dfs2(vector<vector<int>> grid, int i, int j, vector<vector<bool>> visited, int &ans, int M, int N, int sum)
{
    if (sum >= ans)
        return;

    // FUCKED UP: Not checking boundaries at the right place. Ensure (i,j) is within grid bounds.
    if (i < 0 || i >= M || j < 0 || j >= N)
        return;

    // FUCKED UP: Not checking for revisiting cells which may cause cycles.
    if (visited[i][j])
        return;

    // Check if we reached the destination (bottom-right cell)
    if (i == M - 1 && j == N - 1)
    {
        ans = min(ans, sum + grid[i][j]);
        return;
    }

    // Include current cell's value and mark it as visited
    sum += grid[i][j];
    visited[i][j] = true;

    // FUCKED UP: Original code iterated 9 times, including a (0,0) move.
    // Now using 8 directions (all neighbors, excluding staying in place).
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {
        0,
        -1,
        1,
        0,
    };

    for (int k = 0; k < 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs2(grid, ni, nj, visited, ans, M, N, sum);
    }

    // Backtrack: unmark the current cell so it can be used in other paths.
    visited[i][j] = false;
    return;
}

int shortest_path2(vector<vector<int>> grid)
{
    // return the shortest path len
    int ans = INT_MAX;

    // Rows and Columns
    int row = grid.size();
    int column = grid[0].size();

    // FUCKED UP: Passed visited by value in DFS. Now we pass it by reference to avoid unnecessary copying.
    vector<vector<bool>> visited(row, vector<bool>(column, false));

    dfs2(grid, 0, 0, visited, ans, row, column, 0);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    int result = shortest_path(grid);
    cout << "The shortest path sum is: " << result << endl;
    return 0;
}
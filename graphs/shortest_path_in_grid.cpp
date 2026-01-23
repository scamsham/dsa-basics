#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Node
{
public:
    int x;
    int y;
    int distance;
    Node(int x, int y, int distance)
    {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

class Compare
{
public:
    bool operator()(const Node a, const Node b)
    {
        return (a.distance <= b.distance);
    }
};

int shortest_path(vector<vector<int>> grid)
{
    int M = grid.size();
    int N = grid[0].size();

    int i = 0;
    int j = 0;

    vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
    set<Node, Compare> s;

    dist[0][0] = grid[0][0];

    s.insert(Node(0, 0, grid[0][0]));

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    // Dijkstra
    while (!s.empty())
    {
        auto ele = s.begin();
        int e_x = (ele)->x;
        int e_y = (ele)->y;
        int e_dist = (ele)->distance;
        s.erase(ele);

        for (int k = 0; k < 4; k++)
        {
            int nx = dx[k] + e_x;
            int ny = dy[k] + e_y;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] + e_dist < dist[nx][ny])
            {
                Node temp({nx, ny, dist[nx][ny]});
                if (s.find(temp) != s.end())
                {
                    // if no element found in set
                    s.erase(s.find(temp));
                }
                Node newNode({nx, ny, grid[nx][ny] + e_dist});
                s.insert(newNode);
                dist[nx][ny] = grid[nx][ny] + e_dist;
            }
        }
    }

    return dist[M - 1][N - 1];
}

int main()
{
    vector<vector<int>> v = {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}};

    cout << shortest_path(v);
    return 0;
}
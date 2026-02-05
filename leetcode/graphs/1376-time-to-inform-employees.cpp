/**
 * https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
 */

class Solution
{
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> &um, int source, int &count, int &time, vector<bool> &visited)
    {
        visited[source] = true;

        for (auto &x : um[source])
        {
            int employee = x.first;
            int timeToReach = x.second;
            count += timeToReach;
            time = max(time, count);
            if (!visited[employee])
            {
                dfs(um, employee, count, time, visited);
            }
            count -= timeToReach;
        }

        return;
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        // basically, we need to calculate depth
        // dfs -> we need to make sure we save maximum depth for each path
        // bfs -> queue size
        int time = 0, height = 0, source = 0;
        unordered_map<int, vector<pair<int, int>>> um;
        vector<bool> visited(n, false);

        // create a graph
        for (int i = 0; i < n; i++)
        {
            int managerId = manager[i];
            if (managerId == -1)
            {
                source = i;
            }
            else
            {
                // manager will inform ith employee in informTime ith index
                cout << i << " -> " << informTime[i] << endl;
                um[managerId].push_back({i, informTime[i]});
            }
        }

        for (auto &x : um[source])
        {
            // fill up the inform time of head manager
            x.second += informTime[source];
        }

        dfs(um, source, height, time, visited);

        return time;
    }
};
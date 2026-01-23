/*
Busy Life
You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.
In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.
Either you can
watch movie, play DotA and sleep peacefully (or)
date with crush, play DotA and sleep peacefully

Given the start and finish times of activities, print the maximum number of activities. Input is already store in a vector of pairs. Each pair contains the start and end of the activity.
Sample Input
(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)

Output
3

*/

#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int countActivites(vector<pair<int, int>> activities)
{
    // Complete this method
    int n = activities.size();
    // Sort on the finish time
    sort(activities.begin(), activities.end(), compare);

    int count = 0;

    // 'lastFinish' holds the finish time of the last selected activity.
    // Initialize it to -1 (or any value less than the smallest possible start time)
    // so that the first activity is always eligible to be selected.
    int lastFinish = -1;

    // Loop through each activity in the sorted list.
    for (int i = 0; i < n; i++)
    {
        // activity.first is the start time, activity.second is the finish time.
        // If the current activity's start time is greater than or equal to
        // the finish time of the last selected activity, then select it.
        if (activities[i].first >= lastFinish)
        {
            // Increment the count, as we've selected this activity.
            count++;
            // Update lastFinish to the finish time of this activity.
            lastFinish = activities[i].second;
        }
    }

    return count;
}

int main()
{
    vector<pair<int, int>> activities = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

    // Call the maxActivities function and print the result.
    // Expected output for the sample input is 3.
    cout << "Maximum number of non-overlapping activities: " << countActivites(activities) << endl;

    return 0;
}
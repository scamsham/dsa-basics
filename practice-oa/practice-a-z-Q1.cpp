/**
# Code Question 3: SQS Queue Message Insertion
## Problem Statement
Amazon Simple Queue Service (SQS) is a message queuing service in the AWS cloud that allows 
messages to be retrieved by consumers. Each message in the queue is represented by an integer value, 
where positive values indicate messages sent by producers and negative values indicate 
messages retrieved by consumers. The queue's functionality is determined by the "processing load," 
which is the sum of message values over any subarray of messages.

To maintain the stability of the queue, it is crucial that the processing load for any subarray of 
messages is never zero, as a zero processing load would indicate that the queue is functionally obsolete.

To ensure that no subarray has a processing load of zero, your task is to determine the minimum number 
of new messages that must be inserted into the queue. Each inserted message can have any arbitrary 
integer value. The goal is to ensure that after the insertions, the sum of any subarray within the 
queue is never zero.

Given the integer array `messages`, determine the minimum number of insertions required to achieve this.

## Example
Given `n = 5` and `messages = [1, -5, 3, 2, -5]`
The SQS Queue from the subarray [2, 4] has a processing load of 0.
One possible way to modify the given array messages is by inserting a message with value after the third index. 
The updated array becomes [1, -5, 3, 100, 2, -5]. Now, no subarray has a processing load equal to zero.
Hence, the minimum number of messages to be inserted is 1.

## Function Description
Complete the function `getMinInsertion` in the editor below.
`getMinInsertion` has the following parameter:
- `int messages[n]`: an array of non-zero integers, where each subarray represents a SQS Queue.

## Returns
`int`: the minimum number of messages that must be inserted such that each SQS Queue has non zero processing load.



## Input Format For Custom Testing
The first line contains an integer, `n`, the number of elements in `messages`.
Each of the next `n` lines contains a non-zero integer, `messages[i]`.


## Sample Test Cases
### Sample Case 0
**Sample Input For Custom Testing**
```
STDIN      FUNCTION
-----      --------
5      →   messages[] size n = 5
1      →   messages = [1, -5, 3, 2, -5]
-5
3
2
-5
```

**Sample Output**
```
1
```

**Explanation**

The SQS Queue from the subarray [2, 4] has a processing load of 0.

One possible way to modify the given array messages is by inserting a message with value after the third index. The updated array becomes [1, -5, 3, 100, 2, -5]. Now, no subarray has a processing load equal to zero.

Hence, the minimum number of messages to be inserted is 1.

---

### Sample Case 1

**Sample Input For Custom Testing**
```
STDIN      FUNCTION
-----      --------
6      →   messages[] size n = 6
-3     →   messages = [-3, -3, -3, 3, 3, 3]
-3
-3
3
3
3
```

**Sample Output**
```
1
```

**Explanation**

The SQS Queue from subarrays [1, 6], [2, 5], and [3, 4] has a processing load of 0.

One possible way to modify the given array messages is by inserting a message with value 685 after the third index. The updated array becomes [-3, -3, -3, 685, 3, 3, 3]. Now, no subarray has a processing load equal to zero.

Hence, the minimum number of messages to be inserted is 1.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

// TODO: Implement this function
int getMinInsertion(vector<int> messages) {
    // Write your logic here
    
    return 0;
}

int main() {
    // Test cases
    vector<pair<vector<int>, int>> testCases = {
        {{1, -5, 3, 2, -5}, 1},      // Sample Case 0
        {{-3, -3, -3, 3, 3, 3}, 1}   // Sample Case 1
    };
    
    cout << "Running test cases...\n" << endl;
    
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> input = testCases[i].first;
        int expected = testCases[i].second;
        int result = getMinInsertion(input);
        
        cout << "Test Case " << i << ":" << endl;
        cout << "Input:    [";
        for (int j = 0; j < input.size(); j++) {
            cout << input[j];
            if (j < input.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        cout << "Expected: " << expected << endl;
        cout << "Got:      " << result << endl;
        cout << "Status:   " << (result == expected ? "PASS ✓" : "FAIL ✗") << endl;
        cout << "-----------------------------------" << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Helper function to build the tree using pre-order traversal.
// The index is passed by reference so that recursive calls update it.
Node *buildTree(const vector<int> &a, int &index, int n)
{
    if (index >= n)
        return NULL;

    int val = a[index];
    index++;

    // if the current value is -1, it represents a NULL node.
    if (val == -1)
        return NULL;

    // Create the new node and build its subtrees.
    Node *newNode = new Node(val);
    newNode->left = buildTree(a, index, n);
    newNode->right = buildTree(a, index, n);

    return newNode;
}

void printLevelOrder(Node *tree)
{
    if (!tree)
    {
        cout << "No tree";
        return;
    }
    queue<Node *> q;
    q.push(tree);
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << ", ";
            if (temp->left && temp->right)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
            else if (temp->left && !temp->right)
            {
                q.push(temp->left);
            }
            else if (temp->right && !temp->left)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

int findHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
        return 1;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int findDiameter(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
    {
        return 1;
    }

    int current_diameter = (findHeight(root->left) + findHeight(root->right));
    int left_tree_diameter = findDiameter(root->left);
    int right_tree_diameter = findDiameter(root->right);

    return max(max(current_diameter, left_tree_diameter), right_tree_diameter);
}

// Diameter optimized
class HDPair
{
public:
    int height;
    int diameter;
};

HDPair findDiameterInOofN(Node *root)
{
    HDPair p;
    if (!root)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    HDPair leftPair = findDiameterInOofN(root->left);
    HDPair rightPair = findDiameterInOofN(root->right);

    p.height = max(leftPair.height, rightPair.height) + 1;

    int d1 = leftPair.height + rightPair.height;
    int d2 = leftPair.diameter;
    int d3 = rightPair.diameter;

    p.diameter = max(d1, max(d2, d3));

    return p;
}

int replaceWithSum(Node *&root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return root->data;
    }

    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);
    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + root->data;
}

class BalancedPair
{
public:
    bool isBalanced;
    int height;
};

BalancedPair isBalancedTree(Node *root)
{
    BalancedPair p;
    if (!root)
    {
        p.height = 0;
        p.isBalanced = true;
        return p;
    }
    if (!root->left && !root->right)
    {
        p.height = 1;
        p.isBalanced = true;
        return p;
    }

    BalancedPair leftPair = isBalancedTree(root->left);
    BalancedPair rightPair = isBalancedTree(root->right);

    p.height = max(leftPair.height, rightPair.height) + 1;

    if (abs(leftPair.height - rightPair.height) <= 1 && leftPair.isBalanced && rightPair.isBalanced)
    {
        p.isBalanced = true;
    }
    else
    {
        p.isBalanced = false;
    }

    return p;
}

class maxSubset
{
public:
    int inc;
    int exc;
};

maxSubset findMaxSubset(Node *root)
{
    maxSubset ms;
    if (!root)
    {
        ms.inc = 0;
        ms.exc = 0;
        return ms;
    }

    if (!root->left && !root->right)
    {
        ms.inc = root->data;
        ms.exc = 0;
    }

    maxSubset leftNode = findMaxSubset(root->left);
    maxSubset rightNode = findMaxSubset(root->right);

    ms.inc = root->data + leftNode.exc + rightNode.exc;
    ms.exc = max(leftNode.inc, leftNode.exc) + max(rightNode.inc, rightNode.exc);

    return ms;
}

void verticalPrint(Node *tree, map<int, vector<int>> &m, int breadth)
{
    if (!tree)
    {
        return;
    }
    m[breadth].push_back(tree->data);
    verticalPrint(tree->left, m, breadth - 1);
    verticalPrint(tree->right, m, breadth + 1);

    return;
}
void findNodesDownwards(Node *tree, int K)
{
    if (!tree)
    {
        return;
    }
    if (K == 0)
    {
        cout << tree->data << " ";
    }
    findNodesDownwards(tree->left, K - 1);
    findNodesDownwards(tree->right, K - 1);

    return;
}

int printAllNodesAtKDistanceFromTarget(Node *tree, int K, int target)
{
    if (!tree)
    {
        return 0;
    }
    if (tree->data == target)
    {
        findNodesDownwards(tree, K);
        return 1;
    }
    int left = printAllNodesAtKDistanceFromTarget(tree->left, K, target);
    // The target node exists on the left tree
    if (left != -1)
    {
        if (K - left - 2 == 0)
        {
            cout << tree->data;
        }
        else
        {
            findNodesDownwards(tree->right, K - left - 1);
        }
        return 1 + left;
    }
    int right = printAllNodesAtKDistanceFromTarget(tree->left, K, target);
    if (right != -1)
    {
        if (K - right - 2 == 0)
        {
            cout << tree->data;
        }
        else
        {
            findNodesDownwards(tree->left, K - right - 1);
        }
        return 1 + right;
    }
    return -1;
}

int main()
{
    // Input representing pre-order traversal where -1 indicates a NULL node.
    vector<int> v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;
    Node *root = buildTree(v, index, v.size());

    printLevelOrder(root);
    cout << endl;
    cout << "Max subset sum: " << max(findMaxSubset(root).inc, findMaxSubset(root).exc) << endl;
    cout << "Maximum height: " << findHeight(root) << endl;
    cout << "Maximum diameter: " << findDiameter(root) << endl;
    cout << "Maximum diameter in o(n): " << findDiameterInOofN(root).diameter << endl;
    replaceWithSum(root);
    printLevelOrder(root);
    cout << endl;
    isBalancedTree(root).isBalanced == 1 ? cout << "The tree is balanced" : cout << "The tree is not balanced";

    cout << "-- ------------------------- --" << endl;
    vector<int> v2 = {1, 2, 4, -1, -1, 5, 7, -1, 11, -1, -1, 8, 9, -1, -1, 10, -1, -1, 3, -1, 6, -1, -1};
    int index2 = 0;
    Node *tree = buildTree(v2, index2, v2.size());
    printLevelOrder(tree);
    cout << endl;

    map<int, vector<int>> m;
    verticalPrint(tree, m, 0);
    for (auto p : m)
    {
        for (int x : m[p.first])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    int K = 2;
    int target = 2;
    cout << endl
         << " ------------------------------- ";
    cout << endl;

    printAllNodesAtKDistanceFromTarget(tree, K, target);
    return 0;
}

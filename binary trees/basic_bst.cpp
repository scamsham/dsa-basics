#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->data = key;
        this->right = NULL;
        this->left = NULL;
    }
};

void createMinHeightBST(vector<int> a, Node *&newNode, int startIndex, int endIndex)
{
    if (startIndex <= endIndex)
    {
        int mid = (startIndex + endIndex) / 2;
        newNode = new Node(a[mid]);
        createMinHeightBST(a, newNode->left, startIndex, mid - 1);
        createMinHeightBST(a, newNode->right, mid + 1, endIndex);

        return;
    }
    return;
}

Node *createMinHeightBST1(vector<int> a, int startIndex, int endIndex)
{
    if (startIndex <= endIndex)
    {
        int mid = (startIndex + endIndex) / 2;
        Node *newNode = new Node(a[mid]);
        newNode->left = createMinHeightBST1(a, startIndex, mid - 1);
        newNode->right = createMinHeightBST1(a, mid + 1, endIndex);

        return newNode;
    }
    else
    {
        return NULL;
    }
}

void printBst(Node *n)
{
    if (!n)
    {
        return;
    }
    printBst(n->left);
    cout << n->data << " ";
    printBst(n->right);

    return;
}

void findClosestIntegerToK(Node *tree, int &minimum, int &ans, int K)
{
    if (!tree)
    {
        return;
    }

    if (minimum > abs(tree->data - K))
    {
        ans = tree->data;
        minimum = abs(tree->data - K);
    }
    if (K < tree->data)
    {
        findClosestIntegerToK(tree->left, minimum, ans, K);
    }
    else
    {
        findClosestIntegerToK(tree->right, minimum, ans, K);
    }
}

class HL
{
public:
    Node *head;
    Node *tail;
};

HL treeToLL(Node *tree)
{
    HL list;
    if (!tree)
    {
        list.head = NULL;
        list.tail = NULL;
        return list;
    }
    if (!tree->left && !tree->right)
    {
        list.head = tree;
        list.tail = tree;
    }
    // No right subtree
    else if (tree->left && !tree->right)
    {
        HL leftTree = treeToLL(tree->left);
        list.head = leftTree.head;
        leftTree.tail->right = tree;
        tree->left = leftTree.tail;
        list.tail = tree;
    }
    // No left subtree
    else if (tree->right && !tree->left)
    {
        HL rightTree = treeToLL(tree->right);
        list.head = tree;
        tree->right = rightTree.head;
        rightTree.head->left = tree;
        list.tail = rightTree.tail;
    }
    // Both sub trees
    else
    {
        HL leftTree = treeToLL(tree->left);
        HL rightTree = treeToLL(tree->right);

        leftTree.tail->right = tree;
        tree->left = leftTree.tail;
        tree->right = rightTree.head;
        rightTree.head->left = tree;
        list.head = leftTree.head;
        list.tail = rightTree.tail;
    }

    return list;
}

int search(Node *root, int key, int level)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
    {
        return level;
    }

    int left = search(root->left, key, level + 1);
    if (left != -1)
    {
        return left;
    }
    return search(root->right, key, level + 1);
}

bool isBSTUtil(Node *node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
        return true;

    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return false;

    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

int main()
{
    vector<int> v = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48};
    // Node *bst = NULL;
    // createMinHeightBST(v, bst, 0, v.size() - 1);
    // printBst(bst);
    cout << endl;
    Node *tree = createMinHeightBST1(v, 0, v.size() - 1);
    printBst(tree);
    cout << isBSTUtil(tree, INT_MIN, INT_MAX);

    /*
        int minimum = INT_MAX;
        int K = 20;
        int ans = 0;
        findClosestIntegerToK(tree, minimum, ans, K);
        cout << endl;
        cout << "The closest iss: " << ans;
    */
    cout << endl;
    Node *listHead = treeToLL(tree).head;
    while (listHead)
    {
        cout << listHead->data << " -- ";
        listHead = listHead->right;
    }

    return 0;
}
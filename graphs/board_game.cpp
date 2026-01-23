#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;

class Node
{
public:
    char c;
    unordered_map<char, Node *> child;
    bool isTerminal;
    string word;
    Node(char c)
    {
        this->c = c;
        this->isTerminal = false;
        this->word = "";
    }
};

class Trie
{
public:
    Node *trie;
    Trie()
    {
        trie = new Node('\0');
    }

    void addWord(string str)
    {
        Node *temp = trie;
        for (char s : str)
        {
            if (temp->child.find(s) == temp->child.end())
            {
                // Not found
                temp->child[s] = new Node(s);
            }
            temp = temp->child[s];
        }
        temp->isTerminal = true;
        temp->word = str;
    }

    void printHelper(Node *root)
    {
        if (root == nullptr)
            return;

        // If this node marks the end of a word, print it.
        if (root->isTerminal)
        {
            cout << root->word << endl;
        }

        // Recurse for all children.
        for (auto it : root->child)
        {
            printHelper(it.second);
        }
    }

    // Print the entire trie by starting at the root.
    void printTrie()
    {
        printHelper(trie);
    }
};

void dfs(char board[][4], Node *root, int i, int j, bool visited[][4], int M, int N)
{
    char ch = board[i][j];
    // If the character is not present
    if (root->child.count(ch) == 0)
    {
        return;
    }
    visited[i][j] = true;
    root = root->child[ch];

    if (root->isTerminal)
    {
        cout << root->word << endl;
        // Do not return because word can be prefix for other words in the list
    }

    int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    for (int k = 0; k <= 8; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && nj >= 0 && ni < M && nj < N && !visited[ni][nj])
        {
            dfs(board, root, ni, nj, visited, M, N);
        }
    }
    visited[i][j] = false;
    return;
}

int main()
{

    const int M = 3, N = 4;

    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};
    int n = sizeof(words) / sizeof(words[0]);
    char board[M][N] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}};

    Trie t;
    for (int i = 0; i < n; i++)
    {
        t.addWord(words[i]);
    }

    cout << "Words in the Trie:" << endl;
    t.printTrie();
    cout << endl;
    unordered_set<string> result;
    bool visited[M][N] = {0};

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dfs(board, t.trie, i, j, visited, M, N);
        }
    }

    return 0;
}
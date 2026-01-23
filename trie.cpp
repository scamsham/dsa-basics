#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    char key;
    unordered_map<char, Node *> child;
    bool isTerminal;
    string word;
    Node(char k = '\0', bool isTerminal = false, string w = "")
    {
        this->key = k;
        this->isTerminal = isTerminal;
        this->word = w;
    }
};

class Trie
{
public:
    Node *trie = new Node('\0', false, "");

    void addWord(string word)
    {
        Node *temp = trie;
        for (char w : word)
        {
            // check if it does not exists in the map
            if (temp->child.find(w) == temp->child.end())
            {
                // create  anew node
                temp->child[w] = new Node(w, false, "");
            }
            temp = temp->child[w];
        }
        temp->isTerminal = true;
        temp->word = word;

        return;
    }

    void printWordsHelper(Node *temp)
    {
        if (temp->word != "")
        {
            cout << temp->word << endl;
        }

        for (auto &[data, nnode] : temp->child)
        {
            printWordsHelper(temp->child[data]);
        }

        return;
    }

    void printWords()
    {
        Node *temp = trie;
        printWordsHelper(trie);

        return;
    }
};

int main()
{
    Trie t;
    vector<string> words = {"snakes", "cats", "dogs", "watchdogs", "watchclock", "bats", "batman"};

    for (string word : words)
    {
        t.addWord(word);
    }
    t.printWords();
    return 0;
}
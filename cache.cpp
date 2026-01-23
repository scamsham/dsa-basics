#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class Node
{
public:
    string key;
    int value;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRU
{
public:
    unordered_map<string, list<Node>::iterator> m;
    int maxSize;
    list<Node> l;
    int currentSize;
    int currentKey;

    LRU(int size)
    {
        this->maxSize = size;
        this->currentSize = 0;
    }

    void insertKeyValue(string key, int value)
    {
        // 2 cases
        if (m.count(key) > 0)
        {
            // the key already exists
            // update the value
            m[key]->value = value;
        }
        else
        {
            // 2 cases - if the LRU is full or not
            if (l.size() == maxSize)
            {
                // LRU is full
                // delete the least recently used key
                Node lastNode = l.back();
                // remove from map
                m.erase(lastNode.key);
                // remove from list
                l.pop_back();
            }
            // insert the new key
            Node newNode(key, value);
            l.push_front(newNode);
            m[key] = l.begin();
        }
    }

    int *getValue(string key)
    {
        if (m.count(key) == 0)
        {
            cout << "Key not found" << endl;
            return NULL;
        }
        else
        {
            auto it = m[key];
            int value = it->value;
            // update the recently used key
            l.erase(it);
            l.push_front(Node(key, value));

            m[key] = l.begin();
            return &l.begin()->value;
        }
    }

    string mostRecetnlyUsedKey()
    {
        return l.front().key;
    }
};

int main()
{
    LRU lru(6);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("guava", 10);
    lru.insertKeyValue("apple", 10);
    lru.insertKeyValue("orange", 10);
    lru.insertKeyValue("banana", 10);
    lru.insertKeyValue("kiwi", 10);
    cout << "Most recently used key is: " << lru.mostRecetnlyUsedKey() << endl;
    lru.insertKeyValue("banana", 50);
    cout << "Orders of banana: " << *lru.getValue("banana") << endl;
    lru.insertKeyValue("apple", 60);
    lru.insertKeyValue("banana", 70);

    cout << "Most recently used key is: " << lru.mostRecetnlyUsedKey();

    return 0;
}
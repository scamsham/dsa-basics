#include <iostream>
#include <unordered_map>
#include <list>

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

class LruCache
{
public:
    unordered_map<string, list<Node>::iterator> m;
    list<Node> l;
    int maxCapacity;
    int capacity;
    LruCache(int maxCapacity)
    {
        this->maxCapacity = maxCapacity;
        this->capacity = 0;
    }

    // insert to cache
    void addKeyValueToCache(string key, int value)
    {
        if (m.count(key))
        {
            // Key exists → update and move to front
            auto it = m[key];
            l.erase(it);
        }
        else if (l.size() == maxCapacity)
        {
            // Evict LRU item from back
            Node lastNode = l.back();
            m.erase(lastNode.key);
            l.pop_back();
        }

        // Insert new node at front
        l.push_front(Node(key, value));
        m[key] = l.begin();
    }
    // get value from the cache
    int getValue(string key)
    {
        // if the key exists in cache
        if (!m.count(key))
        {
            return -1; // not in cache
        }

        // find it in the list (done)
        // remove it from the list (done)
        // push it on the front (done)
        // return the value from  list front (done)

        // Get the value and remove from current position
        auto it = m[key];
        int value = it->value;
        l.erase(it);

        // Reinsert at front and update map
        l.push_front(Node(key, value));
        m[key] = l.begin();

        return value;
    }

    // fetch the most recent value
    string getMostRecentKey()
    {
        if (!l.empty())
            return l.front().key;
        return "";
    }
};

int main()
{
    LruCache lru(6);
    lru.addKeyValueToCache("mango", 10);
    lru.addKeyValueToCache("guava", 10);
    lru.addKeyValueToCache("apple", 10);
    lru.addKeyValueToCache("orange", 10);
    lru.addKeyValueToCache("banana", 10);
    lru.addKeyValueToCache("kiwi", 10);
    cout << "Most recently used key is: " << lru.getMostRecentKey() << endl;
    lru.addKeyValueToCache("banana", 50);
    cout << "Orders of banana: " << lru.getValue("banana") << endl;
    lru.addKeyValueToCache("apple", 60);
    lru.addKeyValueToCache("banana", 70);

    cout << "Most recently used key is: " << lru.getMostRecentKey();

    return 0;
}
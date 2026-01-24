#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Player {
    public:
        string name;
        int score;
    Player(string n, int s){
        this->name = n;
        this->score = s;
    }
};

// Custom comparator class
class ComparePlayer {
public:
    // This makes it a "functor"
    bool operator()(const Player& p1, const Player& p2) {
        // Logic: Return true if p1 should have lower priority than p2
        // To create a MIN-HEAP (lowest score at top), use >
        return p1.score > p2.score;
    }
};

class CustomCompare {
    public:
        bool operator()(const Player &p1, const Player &p2){
            return p1.score > p2.score;
        }
};

int main() {
    // Syntax: <Type, Container, ComparatorClass>
    priority_queue<Player, vector<Player>, ComparePlayer> pq;

    pq.push(Player("Alice", 50));
    pq.push(Player("Bob", 90));
    pq.push(Player("Charlie", 20));

    // Charlie will be at the top because 20 is the "minimum"
    cout << "Top player: " << pq.top().name << " with score " << pq.top().score;
    
    return 0;
}
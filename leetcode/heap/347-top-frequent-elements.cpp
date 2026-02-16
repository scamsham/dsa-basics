

class Solution {
public:
    struct comparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store frequency
        unordered_map<int, int> um;
        for(int &num: nums){
            um[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        for(auto &x: um){
            if(pq.size() < k){
                pq.push({x.first, x.second});
            }else{
                if(pq.top().second < um[x.first]){
                    cout<<pq.top().second<<" "<<um[x.first]<<endl;
                    pq.pop();
                    pq.push({x.first, x.second});
                }
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
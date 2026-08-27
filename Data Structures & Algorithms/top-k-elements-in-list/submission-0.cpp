class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp; //will sort based on frequency;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i = mp.begin();i != mp.end();i++){
            pq.push({i->second,i->first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};

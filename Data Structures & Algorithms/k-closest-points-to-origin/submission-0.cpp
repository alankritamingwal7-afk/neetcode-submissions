class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //will take max heap for this 
        // max heap will contains {distanc, points};
        priority_queue<pair<int,vector<int>>> q;
        for(auto p:points){
            int dist = p[0]*p[0]+p[1]*p[1];
            q.push({dist,p});
            while(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>> res;
        while(q.size()>0){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

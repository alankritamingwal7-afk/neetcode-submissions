class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh(stones.begin(),stones.end());

        while (maxh.size()>1){
            int x = maxh.top();
            maxh.pop();
            int y = maxh.top();
            maxh.pop();
            if(x!=y){
                maxh.push(abs(y-x));
            }
        }
        return maxh.empty()? 0:maxh.top();
        
    }
};

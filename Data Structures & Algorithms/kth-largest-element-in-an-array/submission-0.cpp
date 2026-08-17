class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // largest kth means to use min heap
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto i: nums){
            minh.push(i);
        }
        while(minh.size()>k){
            minh.pop();
        }
        if(minh.size()==0){
            return -1;
        }
        else{
            return minh.top();
        }
    }
};

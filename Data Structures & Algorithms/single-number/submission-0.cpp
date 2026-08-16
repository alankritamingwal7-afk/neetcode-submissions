class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum = sum^i;
        }
        return sum;     
        
    }
};

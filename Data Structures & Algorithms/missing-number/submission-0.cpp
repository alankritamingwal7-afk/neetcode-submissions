class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int exp = (n*(n+1))/2;
        long long int act = 0;
        for(auto i:nums){
            act +=i;
        }
       return exp-act;
    }
};

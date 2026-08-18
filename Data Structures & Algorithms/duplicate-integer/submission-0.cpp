class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        bool duplicate = false;
        for(auto i:mp){
            if(i.second>1){
                duplicate=true;
                break;
            }
        }
        return duplicate;
        
    }
};
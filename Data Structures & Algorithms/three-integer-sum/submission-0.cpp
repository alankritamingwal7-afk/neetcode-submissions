class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
          set<int> mp;  
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(mp.find(third)!=mp.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                mp.insert(nums[j]);
            }
        } 
         return vector<vector<int>>(ans.begin(), ans.end());
        
    }
};

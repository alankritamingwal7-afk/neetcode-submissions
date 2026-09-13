class Solution {
public:
    void solve(vector<int> ip, vector<int> op, vector<vector<int>>& ans){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        vector<int> op1=op;
        vector<int> op2=op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,ans);
        solve(ip,op2,ans);
    

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(nums,op,ans);
        return ans;
        
    }
};

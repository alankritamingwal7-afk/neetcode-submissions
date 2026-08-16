class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        int res = -1;
        for(auto i: nums){
            if(st.count(i)>0){
                res=i;
                break;
            }
            else{
                st.insert(i);
            }
        }
        return res;       
        
    }
};

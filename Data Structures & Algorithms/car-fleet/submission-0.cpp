class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        //{pos,time}
        vector<pair<int,double>> ans;
        for(int i=0;i<n;i++){
            double t=double(target-position[i])/speed[i];
            ans.push_back({position[i],t});
        }
        // sort according to pos dessending order
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());

        stack<double> st;
        for(auto& i:ans){
            double t=i.second;
            if(st.empty() || t>st.top()){
                st.push(t);
            }
        }
        return st.size();
        
    }
};

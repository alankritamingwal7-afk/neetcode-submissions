class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top().first>temperatures[i]){
                ans.push_back(st.top().second);
            }
            else{
                while(st.size()>0 && st.top().first<=temperatures[i]){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({temperatures[i],i});
        }
        //return ans;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=ans[i]-i;

            }
        }
        return ans;
    }
};

class Solution {
public:
    int countbit(int num){
        int count = 0;
        while(num>0){
            if(num&1){
                count++;
            }
            num >>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n;i++)
        {
            int cc = countbit(i);
            ans.push_back(cc);
        }
        return ans;
        
    }
};

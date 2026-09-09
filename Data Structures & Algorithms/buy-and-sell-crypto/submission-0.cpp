class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]<prices[j]){
                    maxi=max(maxi,(prices[j]-prices[i]));
                }
            }
        }
        return maxi;
        
    }
};

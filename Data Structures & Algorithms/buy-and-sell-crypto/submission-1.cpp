class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // by doing minimum so far
        int mini = INT_MAX;
        int maxi = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            mini = min(prices[i],mini);
            int profit = prices[i]-mini;
            maxi = max(maxi,profit);
        }
        return maxi;
    }
};

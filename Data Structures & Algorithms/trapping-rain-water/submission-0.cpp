class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxl(n);
        vector<int> maxr(n);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        int water_at_building=0;

        for(int i = 1;i<n;i++){
            maxl[i] = max(maxl[i-1],height[i]);
        }
        for(int i = n-2; i>=0;i--){
            maxr[i] = max(maxr[i+1],height[i]);
        }
        for(int i=0 ;i<n;i++){
            water_at_building += min(maxl[i],maxr[i])-height[i];
        }

        return water_at_building;
        
    }
};

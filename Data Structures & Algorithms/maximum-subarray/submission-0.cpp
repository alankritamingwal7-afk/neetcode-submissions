class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current_sum = nums[0];   // best sum ending at current index
        int max_sum = nums[0];       // global maximum

        for(int i = 1; i < n; i++) {
            // either extend the previous subarray or start new from nums[i]
            current_sum = max(nums[i], current_sum + nums[i]);
            // update global maximum
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

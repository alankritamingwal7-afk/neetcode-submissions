class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int longest = 1, streak = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                continue; // skip duplicates
            }
            if(nums[i] == nums[i-1] + 1) {
                streak++;
            } else {
                longest = max(longest, streak);
                streak = 1;
            }
        }
        return max(longest, streak);
    }
};

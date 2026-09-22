#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ss = 0;
        if (n == 0) {
            return 0;
        }
        for (auto& i : nums) {
            ss += i;
        }

        // Check feasibility
        if ((target + ss) % 2 != 0 || abs(target) > ss) return 0;

        int m = (target + ss) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {          // loop should go till n
            for (int j = 0; j <= m; j++) {      // loop should go till m
                dp[i][j] = dp[i - 1][j];        // exclude nums[i-1]
                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; // include nums[i-1]
                }
            }
        }

        return dp[n][m];  // corrected return
    }
};

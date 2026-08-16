class Solution {
public:
int climbStairs(int n) {
    if (n <= 2) return n;          // Base cases
    vector<int> dp(n+1, 0);        // dp[i] = ways to reach step i
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // Transition relation
    }
    return dp[n];
}
};

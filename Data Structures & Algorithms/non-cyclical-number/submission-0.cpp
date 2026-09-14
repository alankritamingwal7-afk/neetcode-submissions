class Solution {
public:
    // Helper function to compute sum of squares of digits
    int digitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        // Use Floyd's cycle detection (fast/slow pointers)
        int slow = n, fast = digitSquareSum(n);
        
        while (fast != 1 && slow != fast) {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        }
        
        return fast == 1;
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        
        int sum = 1; // 1 is always a proper divisor
        
        // Iterate up to the square root of num
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                // If the divisors are different, add the matching pair
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        
        return sum == num;
    }
};
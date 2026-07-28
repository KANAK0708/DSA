class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        // 1. Calculate total sum of the array
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        // 2. Standard Kadane's algorithm to find Maximum Subarray Sum
        int maxSoFar = nums[0];
        int currentMax = 0;
        for (int x : nums) {
            currentMax = std::max(x, currentMax + x);
            maxSoFar = std::max(maxSoFar, currentMax);
        }

        // 3. Modified Kadane's algorithm to find Minimum Subarray Sum
        int minSoFar = nums[0];
        int currentMin = 0;
        for (int x : nums) {
            currentMin = std::min(x, currentMin + x);
            minSoFar = std::min(minSoFar, currentMin);
        }

        // 4. If all numbers are negative, return the single largest element
        if (maxSoFar < 0) {
            return maxSoFar;
        }

        // 5. Return max between normal path and circular wrap-around path
        return std::max(maxSoFar, totalSum - minSoFar);
    }
};
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 0;
        
        // Find the maximum element in the array to set the upper bound
        for (int num : nums) {
            high = max(high, num);
        }
        
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            
            // Calculate the sum after division (rounding up)
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // Equivalent to ceil((double)num / mid)
            }
            
            if (sum <= threshold) {
                ans = mid;          // Valid divisor, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;      // Sum is too large, need a larger divisor
            }
        }
        
        return ans;
    }
};
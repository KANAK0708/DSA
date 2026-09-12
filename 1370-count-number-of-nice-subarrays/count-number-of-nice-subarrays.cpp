class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // Array to store the frequencies of prefix sums (number of odd numbers)
        // Maximum possible odd numbers is n, so size is n + 1
        vector<int> prefixCounts(n + 1, 0);
        
        // Base case: 1 way to have 0 odd numbers before starting
        prefixCounts[0] = 1; 
        
        int currentOdds = 0;
        int result = 0;
        
        for (int num : nums) {
            // Increment currentOdds if the number is odd
            currentOdds += (num % 2 != 0) ? 1 : 0;
            
            // If we've seen enough odd numbers to form a window of size k,
            // add the number of times we saw the prefix with (currentOdds - k) odds
            if (currentOdds >= k) {
                result += prefixCounts[currentOdds - k];
            }
            
            // Record that we've seen the current number of odds
            prefixCounts[currentOdds]++;
        }
        
        return result;

    }
};
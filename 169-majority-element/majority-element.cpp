class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If count falls to 0, we pick a new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // If the current number matches the candidate, increment count.
            // Otherwise, decrement the count (representing a cancellation).
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
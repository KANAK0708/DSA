class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // The right sum is the total sum minus the left sum and the current element
            int rightSum = totalSum - leftSum - nums[i];
            
            if (leftSum == rightSum) {
                return i; // Return the leftmost middle index
            }
            
            // Add current element to leftSum for the next iteration
            leftSum += nums[i]; 
        }
        
        return -1; // No middle index found
    }
};
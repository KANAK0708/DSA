class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            total_sum += num;
        }
        
        vector<int> result(n);
        int left_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            // Right sum is the total sum minus the elements we've passed (left_sum) and the current element
            int right_sum = total_sum - left_sum - nums[i];
            
            // Elements to the left are smaller or equal, so difference is: (nums[i] * count) - left_sum
            int left_diff = (i * nums[i]) - left_sum;
            
            // Elements to the right are greater or equal, so difference is: right_sum - (nums[i] * count)
            int right_diff = right_sum - ((n - 1 - i) * nums[i]);
            
            result[i] = left_diff + right_diff;
            
            // Add current element to left_sum for the next iteration
            left_sum += nums[i];
        }
        
        return result;
    
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        long long left_sum = 0;
        int valid_splits = 0;
        
        // We only go up to nums.size() - 1 because we need at least one element on the right
        for (int i = 0; i < nums.size() - 1; ++i) {
            left_sum += nums[i];
            long long right_sum = total_sum - left_sum;
            
            if (left_sum >= right_sum) {
                valid_splits++;
            }
        }
        
        return valid_splits;
    }
};
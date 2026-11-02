class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long target = total_sum - x;

        // If target < 0, total sum is less than x -> impossible
        if (target < 0) {
            return -1;
        }

        // If target == 0, we must remove all elements
        if (target == 0) {
            return nums.size();
        }

        int n = nums.size();
        int left = 0;
        long long current_sum = 0;
        int max_len = -1;

        // Sliding Window
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

            // Contract window when current_sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }

            // Check if current window sum matches target
            if (current_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }

        return (max_len == -1) ? -1 : (n - max_len);
    }
};
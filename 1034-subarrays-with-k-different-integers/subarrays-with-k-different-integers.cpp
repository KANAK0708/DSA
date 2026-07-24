class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int> freq_far(n + 1, 0);
        vector<int> freq_near(n + 1, 0);

        int left_far = 0;   // Furthest left index with AT MOST k distinct elements
        int left_near = 0;  // Nearest left index with AT MOST (k - 1) distinct elements
        int distinct_far = 0;
        int distinct_near = 0;
        int total_subarrays = 0;

        for (int right = 0; right < n; ++right) {
            // Expand far window
            if (freq_far[nums[right]] == 0) {
                distinct_far++;
            }
            freq_far[nums[right]]++;

            // Expand near window
            if (freq_near[nums[right]] == 0) {
                distinct_near++;
            }
            freq_near[nums[right]]++;

            // Shrink far window if distinct count exceeds k
            while (distinct_far > k) {
                freq_far[nums[left_far]]--;
                if (freq_far[nums[left_far]] == 0) {
                    distinct_far--;
                }
                left_far++;
            }

            // Shrink near window if distinct count reaches k (to keep it at most k - 1)
            while (distinct_near >= k) {
                freq_near[nums[left_near]]--;
                if (freq_near[nums[left_near]] == 0) {
                    distinct_near--;
                }
                left_near++;
            }

            // Valid subarrays starting positions are in range [left_far, left_near - 1]
            total_subarrays += (left_near - left_far);
        }

        return total_subarrays;
    }
};
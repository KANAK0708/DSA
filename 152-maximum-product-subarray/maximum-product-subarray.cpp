class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (size_t i = 1; i < nums.size(); ++i) {
            int current = nums[i];
            
           
            int temp_max = max({current, max_so_far * current, min_so_far * current});
            
            min_so_far = min({current, max_so_far * current, min_so_far * current});
            max_so_far = temp_max;

            result = max(result, max_so_far);
        }

        return result;
    }
};
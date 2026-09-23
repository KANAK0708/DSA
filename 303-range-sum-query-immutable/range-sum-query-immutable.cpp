class NumArray {
private:
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        // prefix[i] will store the sum of elements from nums[0] to nums[i-1]
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // The sum from index 'left' to 'right' is prefix[right + 1] - prefix[left]
        return prefix[right + 1] - prefix[left];
    }
};
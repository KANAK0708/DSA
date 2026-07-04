class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int i = 2; // Pointer to place the next valid element
        
        for (int j = 2; j < nums.size(); j++) {
            // Compare the current element with the element 2 positions behind the write pointer
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i; // i represents the length of the valid array segment
    }
    
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // A set automatically keeps only unique quadruplets
        set<vector<int>> uniqueQuadruplets;
        int n = nums.size();

        // Step 1: Always sort first so our two pointers logic works
        sort(nums.begin(), nums.end());

        // Step 2: Loop for the 1st number
        for (int i = 0; i < n; i++) {
            // Step 3: Loop for the 2nd number
            for (int j = i + 1; j < n; j++) {
                
                // Step 4: Two Pointers for the 3rd and 4th numbers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to avoid integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Found a match! Insert it into our set
                        uniqueQuadruplets.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++; // Sum is too small, move left pointer to get a bigger number
                    } 
                    else {
                        right--; // Sum is too big, move right pointer to get a smaller number
                    }
                }
            }
        }

        // Step 5: Convert the set back into a vector array to return it
        return vector<vector<int>>(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
    }
};
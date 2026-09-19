class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Find the target remainder we need to remove
        int target = totalSum % p;
        if (target == 0) return 0; // Already divisible by p
        
        // Map to store the latest index for a specific prefix sum modulo p
        unordered_map<int, int> modMap;
        modMap[0] = -1; 
        
        long long currentSum = 0;
        int minLen = n;
        
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;
            
            // Calculate the prefix sum mod p that we need to find
            int needed = (currentSum - target + p) % p;
            
            // If we have seen this needed remainder, calculate the subarray length
            if (modMap.count(needed)) {
                minLen = min(minLen, i - modMap[needed]);
            }
            
            // Update the map with the current prefix sum mod p and its index
            modMap[currentSum] = i;
        }
        
        // If minLen equals the length of the array, it means we'd have to remove 
        // the whole array, which is not allowed. Return -1 in that case.
        return minLen == n ? -1 : minLen;
    }
};
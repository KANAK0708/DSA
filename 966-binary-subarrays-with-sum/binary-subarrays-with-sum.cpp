class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int count = 0;
        int current_sum = 0;
        
        vector<int> freq(nums.size() + 1, 0);
        
       
        freq[0] = 1; 
        
        for (int num : nums) {
            current_sum += num;
            
            
            if (current_sum >= goal) {
                count += freq[current_sum - goal];
            }
            
           
            freq[current_sum]++;
        }
        
        return count;

        



    }
};
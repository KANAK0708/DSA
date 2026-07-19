class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int current_sum=0;
        int min_length=INT_MAX;
        for(int j=0;j<nums.size();j++){
            current_sum+=nums[j];
        while (current_sum>=target){
            min_length=min(min_length,j-i+1);

            current_sum-=nums[i];
            i++;
        }

        }
        return (min_length==INT_MAX) ? 0: min_length;
    }
};
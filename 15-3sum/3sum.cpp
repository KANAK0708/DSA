class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;++i){
            if(nums[i]>0)  break;


            if(i>0 && nums[i]==nums[i-1]) continue;


            int low=i+1;
            int high=n -1;


            while(low<high){
                int sum=nums[i] + nums[low] +nums[high];

                if(sum==0) {
                    output.push_back({nums[i],nums[low],nums[high]});

                    while (low < high && nums[low] == nums[low + 1]) low++;
                    // Skip duplicates for the third element
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    
                    // Move both pointers inward after finding a valid triplet
                    low++;
                    high--;
                } 
                else if (sum < 0) {
                    low++; // Sum is too small, need a larger value
                } 
                else {
                    high--; // Sum is too large, need a smaller value
                }
            }
        }
        
        return output;
            
    }
};
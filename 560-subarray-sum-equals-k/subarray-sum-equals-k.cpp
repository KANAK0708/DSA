class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixsum;
        int n=nums.size();
         prefixsum[0]=1;
        int count=0;
        int currentsum=0;

        

        for(int num:nums){
            currentsum += num; 
            
            int target = currentsum - k;

            if (prefixsum.find(target) != prefixsum.end()) {
                count += prefixsum[target];
            }
            
            
            prefixsum[currentsum]++;
        }
        
        return count;
        
        }
    
};
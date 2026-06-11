class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        unordered_map<int,int>map;
        int res=0;

        map[0] = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero++;
            } else {
                one++;
            }
            
            int diff = zero - one;
            
            // If we haven't seen this difference before, store the index
            if (map.find(diff) == map.end()) {
                map[diff] = i;
            } else {
                // If we have seen it, calculate the length of the subarray
                int idx = map[diff];
                int len = i - idx;
                res = max(len, res);
            }
        }
        return res;
    }
};
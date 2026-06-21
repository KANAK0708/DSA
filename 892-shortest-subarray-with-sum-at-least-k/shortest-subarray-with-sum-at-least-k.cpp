class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), minLength = n + 1, left = 0;
        vector<long long> p(n + 1, 0); 
        vector<int> q; 
        
        for (int i = 0; i <= n; ++i) {
            if (i > 0) p[i] = p[i - 1] + nums[i - 1];
            
            
            while (left < q.size() && p[i] - p[q[left]] >= k) {
                minLength = min(minLength, i - q[left++]);
            }
        
            while (left < q.size() && p[i] <= p[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return minLength > n ? -1 : minLength;
    }
};
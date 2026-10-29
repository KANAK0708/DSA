class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *std::max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count total stores needed for this mid value
            long long stores_needed = 0;
            for (int q : quantities) {
                stores_needed += (q + mid - 1) / mid;
            }

            if (stores_needed <= n) {
                ans = mid;        // mid is a valid max, try to find a smaller one
                right = mid - 1;
            } else {
                left = mid + 1;   // mid is too small, increase the limit
            }
        }

        return ans;
    }
};


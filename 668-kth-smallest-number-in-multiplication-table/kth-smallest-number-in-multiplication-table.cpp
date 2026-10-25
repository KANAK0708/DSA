class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count how many numbers in the table are <= mid
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }

            // If count is less than k, we need a larger number
            if (count < k) {
                low = mid + 1;
            } else {
                // Otherwise, mid could be our answer, try to find a smaller valid number
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
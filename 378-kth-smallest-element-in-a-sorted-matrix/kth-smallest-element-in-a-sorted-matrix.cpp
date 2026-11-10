class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count elements less than or equal to mid
            int count = 0;
            int row = n - 1, col = 0;
            
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += (row + 1); // all elements in this column above/including this row are <= mid
                    col++;
                } else {
                    row--;
                }
            }

            if (count < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
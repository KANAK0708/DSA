class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSum = INT_MIN;

        // Fix the left and right boundaries of the column strip
        for (int c1 = 0; c1 < n; ++c1) {
            std::vector<int> rowSum(m, 0);
            for (int c2 = c1; c2 < n; ++c2) {
                // Update row sums for the current column strip (c1 to c2)
                for (int r = 0; r < m; ++r) {
                    rowSum[r] += matrix[r][c2];
                }

                // Find the maximum subarray sum <= k in the rowSum array using a prefix sum and set
                std::set<int> prefixSums;
                prefixSums.insert(0);
                int currentSum = 0;

                for (int sum : rowSum) {
                    currentSum += sum;
                    // We want to find a previous prefix sum `p` such that currentSum - p <= k
                    // Which means p >= currentSum - k
                    auto it = prefixSums.lower_bound(currentSum - k);
                    if (it != prefixSums.end()) {
                        maxSum = std::max(maxSum, currentSum - *it);
                    }
                    prefixSums.insert(currentSum);
                }
            }
        }

        return maxSum;
    }
};
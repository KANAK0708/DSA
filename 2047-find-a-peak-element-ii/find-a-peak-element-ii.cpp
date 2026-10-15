class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int midCol = low + (high - low) / 2;
            
            // Find the row with the maximum element in midCol
            int maxRow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            // Check left and right neighbors
            bool leftIsGreater = (midCol - 1 >= 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            bool rightIsGreater = (midCol + 1 < n) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);
            
            if (!leftIsGreater && !rightIsGreater) {
                // It's a peak element
                return {maxRow, midCol};
            } else if (leftIsGreater) {
                // Search left half
                high = midCol - 1;
            } else {
                // Search right half
                low = midCol + 1;
            }
        }
        
        return {-1, -1};
    }
};
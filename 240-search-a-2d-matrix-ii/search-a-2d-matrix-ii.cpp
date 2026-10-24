class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start from the top-right corner
        int row = 0;
        int col = n - 1;
        
        while (row < m && col >= 0) {
            int current = matrix[row][col];
            
            if (current == target) {
                return true;
            } else if (current > target) {
                // If the current element is greater than the target,
                // move left to eliminate the entire column.
                col--;
            } else {
                // If the current element is smaller than the target,
                // move down to eliminate the entire row.
                row++;
            }
        }
        
        return false;
    }
};
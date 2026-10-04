class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Step 1: Create a 2D prefix sum array 
        // We use an (m+1) x (n+1) grid to avoid going out of bounds when checking row-1 or col-1
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j] 
                                     + prefix[i][j + 1] 
                                     + prefix[i + 1][j] 
                                     - prefix[i][j];
            }
        }
        
        // Step 2: Calculate the block sum for each cell using the prefix matrix
        vector<vector<int>> answer(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Determine the valid boundaries of the k-sized window
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);
                
                // Extract the sum using inclusion-exclusion.
                // We add 1 to the 'end' coordinates (r2+1, c2+1) because our prefix array is 1-indexed.
                answer[i][j] = prefix[r2 + 1][c2 + 1] 
                             - prefix[r1][c2 + 1] 
                             - prefix[r2 + 1][c1] 
                             + prefix[r1][c1];
            }
        }
        
        return answer;
    }
    
};
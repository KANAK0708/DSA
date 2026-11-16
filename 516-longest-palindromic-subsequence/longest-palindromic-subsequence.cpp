class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[j] stores the LPS length for the substring ending at j in the current row
        vector<int> dp(n, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1; // A single character is always a palindrome of length 1
            int prev = 0; // Tracks dp[i + 1][j - 1]
            
            for (int j = i + 1; j < n; ++j) {
                int temp = dp[j]; // Save dp[i + 1][j] before overwriting
                if (s[i] == s[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        
        return dp[n - 1];
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        // dp[i] represents whether the substring s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string can always be segmented
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // If s[0...j-1] is valid and s[j...i-1] is in the dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Move on to the next index i
                }
            }
        }
        
        return dp[n];
    }
};
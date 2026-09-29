class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        int zeros = 0;
        int ones = totalOnes;
        int max_score = 0;
        
        // Iterate up to the second to last character to ensure both substrings are non-empty
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            max_score = max(max_score, zeros + ones);
        }
        
        return max_score;
    }
};
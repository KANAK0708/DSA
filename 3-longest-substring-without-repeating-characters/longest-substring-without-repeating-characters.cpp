class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character was seen before AND its last recorded index 
            // falls inside our current window, shrink the window by jumping 'left'.
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }
            
            // Update or record the last seen index of the current character
            lastSeen[currentChar] = right;
            
            // Calculate the current window size and update maxLength if it's larger
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
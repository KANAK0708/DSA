class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Count frequencies of characters in t
        vector<int> tFreq(128, 0);
        for (char c : t) {
            tFreq[c]++;
        }

        // Track characters in the current window
        vector<int> windowFreq(128, 0);
        
        int left = 0;
        int minLeft = 0;
        int minLen = INT_MAX;
        int required = t.length();
        int formed = 0; // Tracks how many characters match the required frequency

        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s[right];
            
            // If this character is part of t, see if it contributes to matching t's requirement
            if (tFreq[rightChar] > 0) {
                windowFreq[rightChar]++;
                if (windowFreq[rightChar] <= tFreq[rightChar]) {
                    formed++;
                }
            }

            // Shrink the window from the left as long as it remains valid
            while (formed == required) {
                // Update the minimum window if a smaller one is found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char leftChar = s[left];
                // Remove the left character from the window
                if (tFreq[leftChar] > 0) {
                    if (windowFreq[leftChar] <= tFreq[leftChar]) {
                        formed--;
                    }
                    windowFreq[leftChar]--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
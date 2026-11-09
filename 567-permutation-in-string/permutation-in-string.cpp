class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // If s1 is longer than s2, s2 cannot contain a permutation of s1
        if (n1 > n2) return false;
        
        // Frequency arrays for 'a' through 'z'
        std::vector<int> s1_count(26, 0);
        std::vector<int> window_count(26, 0);
        
        // Build frequency profile for s1 and the first window of s2
        for (int i = 0; i < n1; ++i) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        // If the initial window matches, we found a permutation
        if (s1_count == window_count) return true;
        
        // Slide the window across s2
        for (int i = n1; i < n2; ++i) {
            // Add the new character entering the window (right side)
            window_count[s2[i] - 'a']++;
            
            // Remove the character leaving the window (left side)
            window_count[s2[i - n1] - 'a']--;
            
            // Compare character frequency profile
            if (s1_count == window_count) return true;
        }
        
        return false;
    }
};
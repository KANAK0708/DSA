class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60, 0);
        int pairs = 0;
        
        for (int t : time) {
            int rem = t % 60;
            // The complement that would sum to a multiple of 60
            int target = (60 - rem) % 60; 
            
            // Add the number of times we've previously seen the required complement
            pairs += count[target];
            
            // Increment the count of the current remainder
            count[rem]++;
        }
        
        return pairs;
    }
};
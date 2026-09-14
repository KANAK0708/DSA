class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int max_len = 0;
        int score = 0;
        unordered_map<int, int> seen;

        for (int i = 0; i < hours.size(); i++) {
            
            score += hours[i] > 8 ? 1 : -1;


        if (score > 0) {
                max_len = i + 1;
        } else {


            if (seen.find(score - 1) != seen.end()) {
                    max_len = max(max_len, i - seen[score - 1]);
                }
                
                
                if (seen.find(score) == seen.end()) {
                    seen[score] = i;
                }
            }
        }

        return max_len;








    }
};
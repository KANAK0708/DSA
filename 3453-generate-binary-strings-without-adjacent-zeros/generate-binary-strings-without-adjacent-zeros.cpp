class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result = {"0", "1"};

        for (int i = 1; i < n; ++i) {
            vector<string> next;
            for (const string& s : result) {
                // Always valid to append '1'
                next.push_back(s + "1");
                
                // Only append '0' if the last character is '1'
                if (s.back() == '1') {
                    next.push_back(s + "0");
                }
            }
            result = move(next);
        }

        return result;
    }
};
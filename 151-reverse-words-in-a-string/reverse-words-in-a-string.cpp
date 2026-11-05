class Solution {
public:
    string reverseWords(string s) {
      stringstream ss(s);
        string word;
        string result = "";

        // Extract words one by one (stringstream automatically skips spaces)
        while (ss >> word) {
            if (result.empty()) {
                result = word;
            } else {
                result = word + " " + result; // Prepend new word to reverse the order
            }
        }

        return result;
       }
    };
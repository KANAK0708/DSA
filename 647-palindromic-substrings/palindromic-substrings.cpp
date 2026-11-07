class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        
        for (int i = 0; i < n; ++i) {
            count += expandAroundCenter(s, i, i);

            count += expandAroundCenter(s, i, i + 1);
        }

        return count;
    }
private:
    int expandAroundCenter(const string& s, int left, int right) {
        int palindromes = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            palindromes++;
            left--;
            right++;
        }
        return palindromes;

                }
};
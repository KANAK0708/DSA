class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch);
        
        // If character exists in string
        if (index != string::npos) {
            int left = 0;
            int right = index;
            
            // Swap characters moving towards the center
            while (left < right) {
                std::swap(word[left], word[right]);
                left++;
                right--;
            }
        }
        
        return word;
    }
};
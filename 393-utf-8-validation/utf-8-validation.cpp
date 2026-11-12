class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remainingBytes = 0;
        
        for (int num : data) {
            // Only consider the least significant 8 bits
            int byte = num & 255;
            
            if (remainingBytes == 0) {
                // Determine the number of bytes in the current UTF-8 character
                if ((byte >> 7) == 0b0) {
                    remainingBytes = 0; // 1-byte character (0xxxxxxx)
                } else if ((byte >> 5) == 0b110) {
                    remainingBytes = 1; // 2-byte character (110xxxxx)
                } else if ((byte >> 4) == 0b1110) {
                    remainingBytes = 2; // 3-byte character (1110xxxx)
                } else if ((byte >> 3) == 0b11110) {
                    remainingBytes = 3; // 4-byte character (11110xxx)
                } else {
                    return false; // Invalid leading byte
                }
            } else {
                // Continuation bytes must start with '10' (10xxxxxx)
                if ((byte >> 6) != 0b10) {
                    return false;
                }
                remainingBytes--;
            }
        }
        
        // Ensure all multi-byte characters were properly completed
        return remainingBytes == 0;
    }
};
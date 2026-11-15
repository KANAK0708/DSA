class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build multi-digit numbers (e.g., "100[a]")
                k = k * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // Save the current state before entering the nested bracket
                countStack.push(k);
                stringStack.push(currentString);
                
                // Reset for the new inner bracket
                currentString = "";
                k = 0;
            } 
            else if (ch == ']') {
                // Pop the previous string and repeat count
                string decodedString = stringStack.top();
                stringStack.pop();
                int repeatTimes = countStack.top();
                countStack.pop();
                
                // Append the current substring 'repeatTimes' to the previous string
                while (repeatTimes--) {
                    decodedString += currentString;
                }
                currentString = decodedString;
            } 
            else {
                // Regular lowercase English letter
                currentString += ch;
            }
        }

        return currentString;
    }
};
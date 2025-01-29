class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                max++;
                min++;
            } 
            else if (s[i] == ')') {
                max--;
                min--;
            } 
            else { // '*' can be '(' or ')' or empty
                max++;  // Treat '*' as '('
                min--;  // Treat '*' as ')'
            }

            if (min < 0) {
                min = 0; // Can't have negative open brackets
            }

            if (max < 0) {  
                return false; // Too many closing brackets
            }
        }
        return (min == 0);
    }
};

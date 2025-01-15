class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";  // Use a string as the stack
        int n = num.length();
        
        // Traverse each digit in the string
        for (int i = 0; i < n; ++i) {
            // Pop digits from the stack if they are greater than the current digit
            // and we still have digits to remove (k > 0)
            while (!st.empty() && st.back() > num[i] && k > 0) {
                st.pop_back();
                k--;
            }
            // Push the current digit to the stack
            st.push_back(num[i]);
        }
        
        // If k digits were not removed, remove from the end of the stack
        while (k > 0) {
            st.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < st.size() && st[start] == '0') {
            start++;
        }
        
        // Get the resulting number without leading zeros
        string result = st.substr(start);
        
        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

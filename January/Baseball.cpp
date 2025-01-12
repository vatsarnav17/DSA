class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st; // Use stack<int> for arithmetic operations
        
        for (const string& op : operations) {
            if (op == "C") {
                if (!st.empty()) {
                    st.pop(); // Remove the last valid score
                }
            } else if (op == "D") {
                if (!st.empty()) {
                    st.push(2 * st.top()); // Double the last score and push
                }
            } else if (op == "+") {
                if (st.size() >= 2) {
                    int last = st.top(); st.pop();
                    int secondLast = st.top();
                    int sum = last + secondLast;
                    st.push(last); // Push the last score back
                    st.push(sum);  // Push the sum
                }
            } else {
                st.push(stoi(op)); // Convert string to integer and push
            }
        }
        
        int ans = 0; // Initialize sum
        while (!st.empty()) {
            ans += st.top(); // Accumulate scores
            st.pop();
        }
        
        return ans; // Return the total score
    }
};

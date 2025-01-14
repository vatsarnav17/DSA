class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int num : asteroids) {
            bool destroyed = false;

            // Handle collision between positive asteroids in the stack and the current negative asteroid
            while (!st.empty() && st.top() > 0 && num < 0) {
                if (st.top() < -num) {
                    st.pop(); // The positive asteroid is destroyed
                } else if (st.top() == -num) {
                    st.pop(); // Both asteroids are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // The incoming negative asteroid is destroyed
                    break;
                }
            }

            // If the asteroid survives the collision, push it to the stack
            if (!destroyed) {
                st.push(num);
            }
        }

        // Prepare the result from the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end()); // Reverse to maintain input order

        return ans;
    }
};
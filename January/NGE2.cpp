class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, -1); // Result vector initialized with -1
        stack<int> st; // Stack to keep track of elements

        for (int i = 2 * n - 1; i >= 0; i--) {
            // Access nums[i % n] instead of arr[i % n]
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) { // Only update result for the first iteration of nums
                arr[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]); // Push the current element
        }

        return arr;
    }
};

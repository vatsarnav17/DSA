class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ngm;
        stack<int> st;
        for(int nums:nums2)
        {
            while(!st.empty() && st.top()<nums)
            {
                ngm[st.top()] = nums;
                st.pop();
            }
            st.push(nums);
        }
        while(!st.empty())
        {
            ngm[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for(int num:nums1)
        {
            ans.push_back(ngm[num]);
        }
        return ans;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n), nse(n), pge(n), nge(n);
        stack<int> st;
        
        //find previous smaller or equal elements
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        //clear the stack
        while(!st.empty()) st.pop();

        //find previous greater or equal elements
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }

        //clear the stack
        while(!st.empty()) st.pop();

        //find next smaller elements
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }

         //clear the stack
        while(!st.empty()) st.pop();

        //find next greater elements
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++){
            res = res + (long long)(nums[i]*(long long)((i - pge[i]) *(nge[i] - i))) -  (long long)(nums[i]*(long long)((nse[i] - i) * (i - pse[i])));
        }
        return res;
    }
};

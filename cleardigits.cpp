class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans;
        for(char ch:s)
        {
            if(!st.empty() && isdigit(ch))
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
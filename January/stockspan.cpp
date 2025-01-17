class StockSpanner {
public:
    int index;
    stack<pair<int,int>> st;
    StockSpanner() {
        index =-1; 
        // st.clear();
    }
    
    int next(int price) {
        index+=1;
        int ans;
        while(!st.empty() && st.top().first<= price )
        {
            st.pop();
        }
        ans = index - (st.empty()? -1: st.top().second);
        st.push({price,index});
        return ans;
    }
};
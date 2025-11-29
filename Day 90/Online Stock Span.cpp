/*
https://leetcode.com/problems/online-stock-span/solutions/3391419/cjavapythonjavascript-monotonic-stack-qu-d8u9
*/

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first <= price){
            span+=st.top().second;
            st.pop();
        } 
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
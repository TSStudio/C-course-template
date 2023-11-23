#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        st.emplace(0, INT_MAX);
    }
    int day = 0;
    int next(int price) {
        day++;
        int ans = 1;
        while (st.top().second <= price) {
            st.pop();
        }
        ans = day - st.top().first;
        st.emplace(day, price);
        return ans;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
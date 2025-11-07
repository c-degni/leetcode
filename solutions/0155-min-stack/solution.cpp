class MinStack {
public:
    int globalMin;
    int n;
    vector<pair<int, int>> st;

    MinStack() {
        globalMin = INT_MAX;
        n = 0;
    }
    
    void push(int val) {
        st.push_back({val, globalMin});
        globalMin = min(globalMin, val);
        n++;
    }
    
    void pop() {
        globalMin = topPair().second;
        st.pop_back();
        n--;
    }
    
    int top() {
        return st[n - 1].first;
    }

    pair<int, int> topPair() {
        return st[n - 1];
    }
    
    int getMin() {
        return globalMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

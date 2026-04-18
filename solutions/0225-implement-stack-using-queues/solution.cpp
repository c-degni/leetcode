class MyStack {
public:
    std::queue<int> q1;
    std::queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int tmp;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        tmp = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    int top() {
        int tmp;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        tmp = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(tmp);
        return tmp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

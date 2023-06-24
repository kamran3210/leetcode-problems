class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mins.size() == 0 || val <= mins.top()) mins.push(val);
    }
    
    void pop() {
        if (st.top() == mins.top()) mins.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> mins;
    stack<int> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
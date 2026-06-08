class MinStack {

public:
   stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int t=st.top();
        return t;
    }
    
    int getMin() { 
        int min_val = INT_MAX;
        stack<int> temp;

        while(!st.empty()){
            min_val = min(st.top(), min_val);
            temp.push(st.top());
            st.pop();
        }

        // restore stack
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return min_val;
    }
};

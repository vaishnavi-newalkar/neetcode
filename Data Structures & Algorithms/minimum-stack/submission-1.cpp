class MinStack {
public:
    stack<int> st;
    stack<int> minTrack;
    int minEle=INT_MAX;
    MinStack() {     
    }
    
    void push(int val) {
        st.push(val);
        if(minTrack.empty() || val<=minTrack.top()){
            minTrack.push(val);
        }
    }
    
    void pop() {
        
        if(st.top() == minTrack.top())
            minTrack.pop();
        st.pop();    
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return minTrack.top();
        }
    
};

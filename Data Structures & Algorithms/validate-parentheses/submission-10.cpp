class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        if(str.size()==1) return false;
        for(char s:str){
            if(s=='[' || s=='{' || s=='('){
                st.push(s);
            }
            else {
                if(st.empty()) return false;
                if(s==']' && st.top()!='[' ||
                s=='}' && st.top()!='{'||
                s==')' && st.top()!='(') return false;
                if(s==']' && st.top()=='[' ||
                s=='}' && st.top()=='{'||
                s==')' && st.top()=='('){
                st.pop();
                }
            }

        }
        return st.empty();
    }
};

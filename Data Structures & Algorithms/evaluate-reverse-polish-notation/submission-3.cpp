#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string i: tokens){
            if(i!="*" && i!="+" && i!="/" && i!="-"){
              st.push(stoi(i));
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(i=="*"){
                    int c=a*b;
                    st.push(c);
                }
                else if(i=="/"){
                    int c=b/a;
                    st.push(c);
                }
                else if(i=="-"){
                    int c=b-a;
                    st.push(c);
                }
                else if(i=="+"){
                    int c=a+b;
                    st.push(c);
                }

            }

        }
        return st.top();
    }
};

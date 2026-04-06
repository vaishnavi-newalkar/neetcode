class Solution {
public:
    unordered_map<char,char> mp = {
        {')','('},
        {'}','{'},
        {']','['}
    };
    bool isValid(string str) {
        stack<char> st;
        for(char s: str){
         if(mp.count(s)){
            if(st.empty()|| st.top()!=mp[s]) return false;
            st.pop();
         }else{
            st.push(s);
         }
        }
        return st.empty();
    }
};

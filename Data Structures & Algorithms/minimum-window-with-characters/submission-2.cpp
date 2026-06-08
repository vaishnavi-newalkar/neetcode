class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        vector<int> freq(128,0);
        for(char c: t){
            freq[c]++;
        }
        int min_len=INT_MAX;
        int count =t.size();
        int start=0;
        for(int r=0;r<s.size();r++){
            if(freq[s[r]]>0){
                count--;}
            freq[s[r]]--;
            
            while(count ==0){
                if(r-l+1<min_len){
                    min_len=r-l+1;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) count++;
                l++;
            }
        }
        if(min_len==INT_MAX) return "";
        return s.substr(start,min_len);
    }
};

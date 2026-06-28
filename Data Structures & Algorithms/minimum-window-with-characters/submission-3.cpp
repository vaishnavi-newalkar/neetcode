class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        int formed=0; int req=0;
         string ans="";
        for(char c: t){
            if(!need.contains(c)){
                req++;
            }
            need[c]++;

        } 
        int l=0;
        for(int r=0;r<s.length();r++){

            if(need.contains(s[r])) {
                window[s[r]]++;
            if( window[s[r]]==need[s[r]]) formed++;
            }

            while(formed == req){
                if(ans.empty() || ans.length()> (r-l+1)){
                    ans=s.substr(l,r-l+1);
                }
            if(need.contains(s[l])){ window[s[l]]--;
                
                if(window[s[l]] < need[s[l]]) formed--;}
                l++;
            }
            
        }
        return ans;
    }
};

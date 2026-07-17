class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1) return s.length();
        int l=0,r=1;
        unordered_set<char> h;
        h.insert(s[0]);
        int ans=1;
        while(l<r && r<s.size()){

        while(h.find(s[r]) != h.end()){
             h.erase(s[l]);
             l++;
        }
        h.insert(s[r]);
        r++;
        ans=max(ans, r-l);
        }
        return ans;
    }
};

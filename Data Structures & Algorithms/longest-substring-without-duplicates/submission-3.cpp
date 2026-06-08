class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int max_len=0;
        int n=s.size();
        vector<int> freq(128,0);
        int len=0;
        for(int r=0;r<n;r++){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            len=r-l+1;
            max_len=max(len,max_len);
        }
        return max_len;
    }
};

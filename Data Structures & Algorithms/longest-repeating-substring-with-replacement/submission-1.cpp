class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int max_len=0;
        int n=s.size();
        vector<int> freq(26,0);
        int maxFreq=0;
           
        for(int r=0;r<n;r++){
           freq[s[r]-'A']++;
           maxFreq = max(maxFreq, freq[s[r]-'A']);
           while((r-l+1)-maxFreq>k){
            freq[s[l] - 'A']--;
            l++;
           }
           max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};

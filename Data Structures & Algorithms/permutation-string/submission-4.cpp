class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int n=s1.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char c:s1){
            freq1[c-'a']++;
        }
        for(int r=0;r<s2.size();r++){
          freq2[s2[r]-'a']++;  
          while(r-l+1>n){
            freq2[s2[l]-'a']--;
            l++;
          }
          if(freq1==freq2){
            return true;
          }
        }
        return false;
    }
};

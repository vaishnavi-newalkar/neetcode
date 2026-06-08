class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2= s2.size();
        
        if(n1>n2) return false;
        vector<int> freq1(26,0), freq2(26,0);

        // freq at s1

        for(char c:s1){
            freq1[c-'a']++;
        }
        int l=0;

        for(int i=0;i<n2;i++){
            freq2[s2[i]-'a']++;

            if(i-l+1>n1){
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

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int r=l+s1.size();
        unordered_map<char,int>freqS2;
        unordered_map<char,int> freqS1;
        for(auto c: s1){
            freqS1[c]++;
        }
        while(l + s1.size() <= s2.size()){
            r=l+s1.size();
             for(int i=l;i<r;i++){
                freqS2[s2[i]]++;
             }
             if(freqS1!=freqS2){
                l++;
             }
             else{
                return true;
             }
             freqS2.clear();
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size())
        return false;
        int l=0;
        int r=l+s1.size();
        unordered_map<char,int>freqS2;
        unordered_map<char,int> freqS1;
        for(auto c: s1){
            freqS1[c]++;
        }
        for (int i = l; i < r; i++)
           freqS2[s2[i]]++;

        if(freqS1==freqS2) return true;
        else{
        while(r<s2.size()){                      
                freqS2[s2[l]]--;
                
                if (freqS2[s2[l]] == 0)freqS2.erase(s2[l]);
                l++;
                freqS2[s2[r]]++;
                r++;   
                if(freqS1==freqS2) return true;  
        }
        
        }
        return false;
    }
};

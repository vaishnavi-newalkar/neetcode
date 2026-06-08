class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r= *max_element(piles.begin(),piles.end());
      
        int res=r;
        if(h==piles.size()) return r;
        int l=1;
        while(l<=r){
            int k=(l+r)/2;
            int hours=0;
            for(int i:piles){
                hours+=ceil(((double)i/k));
            }
            if(hours<=h){
                res=min(res,k);
                r=k-1;
            }
            else{
                l=k+1;
            }   
        }
        return res;
    }
};

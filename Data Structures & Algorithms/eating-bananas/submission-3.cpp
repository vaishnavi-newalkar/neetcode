class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l=1,r=piles[piles.size()-1];
        int ans=INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            int sum=0;
            for(int i=0;i<piles.size();i++){
                sum+=ceil((piles[i]*1.0/mid));
            }
            if(sum<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
             
        }
        return ans;
    }
};

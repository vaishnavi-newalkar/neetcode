class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int k=0;
    KthLargest(int k, vector<int>& nums) {    
        for(int i:nums){
          pq.push(i);
          if(pq.size()>k){
            pq.pop();
          }
        }
        this->k=k;
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > k)
           pq.pop();
        return pq.top();
    }
};

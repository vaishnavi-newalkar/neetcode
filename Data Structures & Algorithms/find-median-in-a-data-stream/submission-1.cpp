class MedianFinder {
public:
    MedianFinder() {
        
    }
    vector<int> data;
    void addNum(int num) {
        data.push_back(num);
        sort(data.begin(),data.end());
    }
    
    double findMedian() {
        int a = data.size();
        if(a==0) return 0.0 ;
        if(a%2==0) return (double(data[a/2]+data[(a/2)-1]))/2;
        else return data[a/2];
        }    
};

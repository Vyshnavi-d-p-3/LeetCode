class MedianFinder {
    vector<int> store;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(store.empty()) store.push_back(num);
        else store.insert(lower_bound(store.begin(), store.end(), num), num);
    }
    
    double findMedian() {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
    priority_queue<int> lo; // Max Heap
    priority_queue<int, vector<int>, greater<int>> hi; // Min Heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // if(store.empty()) store.push_back(num);
        // else store.insert(lower_bound(store.begin(), store.end(), num), num);
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
        // Return the median of current data stream
    double findMedian() {
        // int n = store.size();
        // return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
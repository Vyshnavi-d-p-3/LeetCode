class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Approach 1 : Using MinHeap - Prioirity Queue
        // Time Complexity is O(nlogk) and Space Complexity O(n)
        // unordered_map<int, int>  freqMap;
        // for(int num : nums){
        //     freqMap[num]++;
        // }
        // auto cmp =  [](pair<int, int> a, pair<int, int> b) {
        //     return a.second > b.second; 
        // };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        // for(auto& [num, freq]: freqMap){
        //     minHeap.push({num, freq});
        //     if(minHeap.size() > k) {
        //         minHeap.pop();
        //     }
        // }

        // vector<int> result;
        // while(!minHeap.empty()){
        //     result.push_back(minHeap.top().first);
        //     minHeap.pop();
        // }
        // return result;

        // Approach 2 : Using Frequency Array 
        // Time Complexity : O(n) , Space Complexity : o(n)
        vector<int> result;
        unordered_map<int, int> freqMpp;
        for(int num : nums){
            freqMpp[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto& [num, freq] : freqMpp){
            bucket[freq].push_back(num);
        }
        for(int i = bucket.size()-1 ; i >= 0 && result.size() < k ; --i){
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }
        return result;
    }
};
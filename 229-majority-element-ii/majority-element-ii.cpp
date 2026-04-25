class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementCount;
        int n = nums.size() / 3;
        vector<int> majorityElements;
        for(int num: nums) {
            if(elementCount.find(num) != elementCount.end()) {
                elementCount[num]++;
            }else{
                elementCount[num] = 1;
            }
        }
        for(auto element: elementCount) {
            if(element.second > n ) {
                majorityElements.push_back(element.first);
            }
        }
        return majorityElements;
    }
};

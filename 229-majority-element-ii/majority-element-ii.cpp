// Approach: Hashing(TC- O(n), SC(O(n)))
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> elementCount;
//         int n = nums.size() / 3;
//         vector<int> majorityElements;
//         for(int num: nums) {
//             if(elementCount.find(num) != elementCount.end()) {
//                 elementCount[num]++;
//             }else{
//                 elementCount[num] = 1;
//             }
//         }
//         for(auto element: elementCount) {
//             if(element.second > n ) {
//                 majorityElements.push_back(element.first);
//             }
//         }
//         return majorityElements;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        vector<int> res;
        unordered_map<int,int> mpp;
        int n = nums.size();
        int min = (int)(n/3)+1;
        for(int num: nums){
            mpp[num]++;
            if(mpp[num] == min) {
                res.push_back(num);
            }
            if(res.size() == 2) break;
        }
        return res;
    }
};

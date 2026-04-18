class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int num: nums){
            if(counts.find(num) == counts.end()){
                counts[num] = 1;
            }else {
                counts[num]++;
            }
        }
        for(auto entry : counts) {
            if(entry.second > nums.size() / 2) return entry.first;
        }
        return -1;
    }
};



// Moors Voting Algorithm
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int el;
//         int count = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(count == 0) {
//                 count = 1;
//                 el = nums[i];
//             }else if(nums[i] == el) {
//                 count++;
//             }else{
//                 count--; 
//             }
//         }
//         int count1 = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == el){
//                 count1++;
//             }
//         }
//         if(count1 > (nums.size()/2)) {
//             return el;
//         }
//         return -1;
//     }
// };
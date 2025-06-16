class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Approach 1 : Time Complexity O(nlogn) SpaceComplexity O(K)
        // if(nums.size() == 0){
        //     return 0;
        // }
        // sort(nums.begin(), nums.end());
        // int count = 1;
        // int temp = 1 ;
        // for(int i = 0; i < nums.size()-1; i++) {
        //     if((nums[i] == nums[i+1]) || (nums[i] == (nums[i+1] - 1) )) {
        //         if((nums[i] == (nums[i+1] - 1))){
        //             temp++; 
        //         }            
        //     }else {
        //         count = max(temp, count);
        //         temp = 1;
        //     }
        //     count = max(temp, count);
        // }
        // return count;

        // Approach 2 : Using unordered_set which has Time Complexity - O(N) and Space Complexity - O(N)
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(int num:numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int length = 1;
                while(numSet.find(num+length) != numSet.end()){
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
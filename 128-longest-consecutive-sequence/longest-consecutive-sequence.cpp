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
        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longest = 0;
        // for(int num:numSet){
        //     if(numSet.find(num - 1) == numSet.end()){
        //         int length = 1;
        //         while(numSet.find(num+length) != numSet.end()){
        //             length++;
        //         }
        //         longest = max(longest, length);
        //     }
        // }
        // return longest;


        // Approach 3 : Using unordered map with TC: O(N) and SC: O(N)
        unordered_map<int, int> mp;
        int maxLen = 0;
        for(int num: nums){
            if(!mp[num]){
                mp[num] = mp[num-1] + mp[num+1] + 1;
                mp[num - mp[num-1]] = mp[num];
                mp[num + mp[num+1]] = mp[num];
                maxLen = max(maxLen, mp[num]);
            }
        }
        return maxLen;

        // Approach 4 : Using Hashset TC: O(N), SC: O(N)
        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longest = 0;

        // for (int num : nums) {
        //     if (!numSet.count(num - 1)) {  // start of a sequence
        //         int currNum = num;
        //         int currStreak = 1;

        //         while (numSet.count(currNum + 1)) {
        //             currNum += 1;
        //             currStreak += 1;
        //         }

        //         longest = max(longest, currStreak);
        //     }
        // }

        // return longest;
    }
};
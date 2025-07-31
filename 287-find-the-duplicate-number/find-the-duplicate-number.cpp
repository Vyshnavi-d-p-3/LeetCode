class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Appraoch 1 - Set TC : O(n*2*logn), SC : O(N);
        // unordered_set<int> s;
        // for(int num : nums) {
        //     if(s.count(num)) {
        //         return num;
        //     }
        //     s.insert(num);
        // }
        // return -1;

        // Approach 2 : Floyds Algorithm - Hair and Tail Algorithm , TC : O(n), SC : O(1) 
        int slow = nums[0];
        int fast = nums[0];

        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) {
                break;
            }
        }

        int slow2 = nums[0];

        while(slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};

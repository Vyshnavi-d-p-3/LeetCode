class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int i = 0;
        while(!s.count(nums[i])){
            s.insert(nums[i]);
            i++;
        }
        return nums[i];
    }
};